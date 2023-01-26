/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/26 15:09:04 by fpurdom       ########   odam.nl         */
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
	return ((t_vect3){
		colour >> 24 & 255,
		colour >> 16 & 255,
		colour >> 8 & 255
	});
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

	//vect3_print("normal: ", pixel_dir);
	d = vect3_dot_product(pixel_dir, light_dir);
	if (d < 0)
		d = 0;
	//printf("d = %f\n", d);
	rgba = give_rgba(colour) * d;
	ret[0] = sqrt((pow(rgba[0], 2) + pow(shadow >> 24 & 255, 2)) / 2);
	if (ret[0] < (shadow >> 24 & 255))
		ret[0] = shadow >> 24 & 255;
	ret[1] = sqrt((pow(rgba[1], 2) + pow(shadow >> 16 & 255, 2)) / 2);
	if (ret[1] < (shadow >> 16 & 255))
		ret[1] = shadow >> 16 & 255;
	ret[2] = sqrt((pow(rgba[2], 2) + pow(shadow >> 8 & 255, 2)) / 2);
	if (ret[2] < (shadow >> 8 & 255))
		ret[2] = shadow >> 8 & 255;
	return (get_rgba(ret[0], ret[1], ret[2], 255));
}

static t_vect3	get_normal(t_vect3 start, t_object *saved_obj)
{
	if (saved_obj->type == SPHERE)
		return (vect3_normalize(saved_obj->pos, start));
	else if (saved_obj->type == PLANE || saved_obj->type == CIRCLE)
		return (saved_obj->orient);
	else if (saved_obj->type == CYLINDER)
		return (vect3_normalize(saved_obj->pos + (vect3_dot_product(start -
				saved_obj->pos, saved_obj->orient) * saved_obj->orient), start));
	return (vect3_0());
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, t_object *saved_obj, double t)
{
	const t_vect3		start = scene->camera.pos + ray * t;
	const t_vect3		normal = get_normal(start, saved_obj);
	const double		dist = vect3_abs(start - scene->light.pos);
	const int			shadow = get_shadow(saved_obj->color,
								scene->amlight.brightness);
	t_double_intersect	intersects;
	t_object			*objs;

	objs = scene->objs;
	while (objs)
	{
		if (objs->type == SPHERE)
			intersects = sphere_collision(start, vect3_normalize(start, scene->light.pos), objs->pos, objs->radius);
		else if (objs->type == PLANE)
			intersects = plane_collision(start, scene->light.pos, objs->pos, objs->orient);
		else if (objs->type == CYLINDER)
			intersects = cyl_collision(scene->light.pos, start, objs);
		else if (objs->type == CIRCLE)
			intersects = circle_collision(scene->light.pos, start, objs);
		if ((intersects.t1 > 0.00000001 || intersects.t2 > 0.00000001) && (intersects.t1 < dist || intersects.t2 < dist))
			return (shadow);
		objs = objs->next;
	}
	return (get_light(vect3_normalize(start, scene->light.pos), normal, saved_obj->color, shadow));
}
