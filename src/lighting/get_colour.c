/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/20 20:00:12 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdbool.h>
#include <math.h>

#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static t_vect3	give_rgba(int colour)
{
	t_vect3	colours;

	colours.x = colour >> 24 & 255;
	colours.y = colour >> 16 & 255;
	colours.z = colour >> 8 & 255;
	return (colours);
}

static int	get_shadow(int rgba, double intensity)
{
	return (get_rgba((rgba >> 24 & 255) * intensity, (rgba >> 16 & 255) * intensity, (rgba >> 8 & 255) * intensity, 255));
}

static int	get_light(t_vect3 light_dir, t_vect3 pixel_dir, int colour, int shadow)
{
	float	d;
	t_vect3	rgba;
	t_vect3	ret;

	d = vect3_dot_product(pixel_dir, light_dir);
	rgba = vect3_multiply(give_rgba(colour), d);
	ret.x = sqrt((pow(rgba.x, 2) + pow(shadow >> 24 & 255, 2)) / 2);
	if (ret.x < (shadow >> 24 & 255))
		ret.x = shadow >> 24 & 255;
	ret.y = sqrt((pow(rgba.y, 2) + pow(shadow >> 16 & 255, 2)) / 2);
	if (ret.y < (shadow >> 16 & 255))
		ret.y = shadow >> 16 & 255;
	ret.z = sqrt((pow(rgba.z, 2) + pow(shadow >> 8 & 255, 2)) / 2);
	if (ret.z < (shadow >> 8 & 255))
		ret.z = shadow >> 8 & 255;
	return (get_rgba(ret.x, ret.y, ret.z, 255));
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, t_object *saved_obj, double t)
{
	t_double_intersect	intersects;
	t_vect3				start;
	t_vect3				normal;
	t_object			*objs;
	double				dist;
	int					shadow;

	objs = scene->objs;
	start = vect3_add(scene->camera.pos, vect3_multiply(ray, t));
	dist = vect3_abs(vect3_substract(start, scene->light.pos));
	shadow = get_shadow(saved_obj->color, scene->amlight.brightness);
	if (saved_obj->type == SPHERE)
		normal = vect3_normalize(saved_obj->coords, start);
	else if (saved_obj->type == PLANE)
		normal = saved_obj->orientation;
	while (objs)
	{
		if (objs->type == SPHERE)
			intersects = sphere_collision(start, vect3_normalize(start, scene->light.pos), objs->coords, objs->radius);
		else if (objs->type == PLANE)
			intersects = plane_collision(start, scene->light.pos, objs->coords, objs->orientation);
		else if (objs->type == CYLINDER)
			intersects = cylinder_collision(ray, scene->camera.pos, *objs);
		if ((intersects.t1 > 0.00000001 || intersects.t2 > 0.00000001) && (intersects.t1 < dist || intersects.t2 < dist))
			return (shadow);
		objs = objs->next;
	}
	return (get_light(vect3_normalize(start, scene->light.pos), normal, saved_obj->color, shadow));
}
