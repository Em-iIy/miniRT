/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/03/17 13:43:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

static double	get_intersect(t_object *obj, t_vect3 start,
t_vect3 light_pos)
{
	if (obj->type == SPHERE)
		return (sphere_coli(start, vect3_normalize(start, light_pos),
				obj->pos, obj->radius));
	else if (obj->type == PLANE)
		return (plane_coli(start, vect3_normalize(start, light_pos),
				obj->pos, obj->orient));
	else if (obj->type == CYLINDER)
		return (cylinder_coli(vect3_normalize(start, light_pos),
				start, obj));
	else if (obj->type == CIRCLE)
		return (circle_coli(vect3_normalize(start, light_pos), start, obj));
	return (0);
}

int	get_pixel_color(t_vect3 ray, t_scene *scene, t_object *saved, double t)
{
	const t_point	point = {
		.pos = scene->camera.pos + ray * t,
		.colour = saved->color,
		.cam_ray = ray,
		.light_ray = vect3_normalize(point.pos, scene->light.pos),
		.normal = get_normal(point.pos, saved) * (double)saved->inside,
		.light_dist = vect3_abs(point.pos - scene->light.pos)
	};
	double			temp;
	t_object		*objs;
	t_vect3			ret;

	ret = get_ambient(scene->amlight.colour) * point.colour;
	objs = scene->objs;
	while (objs)
	{
		temp = get_intersect(objs, point.pos, scene->light.pos);
		if (temp > 0.0000001 && temp < point.light_dist)
			return (get_int_rgba(ret * point.colour));
		objs = objs->next;
	}
	return (get_int_rgba(ret + get_phong(point, scene)));
}
