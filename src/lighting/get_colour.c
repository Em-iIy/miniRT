/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/02/08 18:43:51 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

static t_intersect	get_intersects(t_object *obj, t_vect3 start,
t_vect3 light_pos)
{
	t_intersect	intersects;

	if (obj->type == SPHERE)
		intersects = sphere_coli(start, vect3_normalize(start, light_pos),
				obj->pos, obj->radius);
	else if (obj->type == PLANE)
		intersects = plane_coli(start, vect3_normalize(start, light_pos),
				obj->pos, obj->orient);
	else if (obj->type == CYLINDER)
		intersects = cylinder_coli(vect3_normalize(start, light_pos),
				start, obj);
	else if (obj->type == CIRCLE)
		intersects = circle_coli(vect3_normalize(start, light_pos), start, obj);
	return (intersects);
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, t_object *saved, double t)
{
	const t_vect3	start = scene->camera.pos + ray * t;
	const t_vect3	normal = get_normal(start, saved);
	const double	dist = vect3_abs(start - scene->light.pos);
	t_intersect		intersects;
	t_object		*objs;

	objs = scene->objs;
	while (objs)
	{
		intersects = get_intersects(objs, start, scene->light.pos);
		if ((intersects.t1 > 0.00000001 || intersects.t2 > 0.00000001)
			&& (intersects.t1 < dist || intersects.t2 < dist))
			return (get_int_rgba(
					get_ambient(saved->color, scene->amlight.colour)));
		objs = objs->next;
	}
	return (get_light(vect3_normalize(
				start, scene->light.pos), normal, saved->color, scene, ray));
}
