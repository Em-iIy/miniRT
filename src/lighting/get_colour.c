/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:37:29 by fpurdom           #+#    #+#             */
/*   Updated: 2023/02/09 19:00:28 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

static bool	check_intersects(t_intersect isect, double dist)
{
	// this version fucks with cylinder shadows when the light is outside
	// to see run test_scene.rt when returning this
	return ((isect.t1 > 0.00000001 || isect.t2 > 0.00000001)
		&& (isect.t1 < dist || isect.t2 < dist));
	// this version fucks with cylinder shadows when the light is inside
	// to see run cyl.rt when returning this
	return (((isect.t1 > 0.00000001 && isect.t2 > 0.00000001))
		&& (isect.t1 < dist || isect.t2 < dist));

	
	// when both the camera and light are inside the cylinder it works fine
	// i think the issue is caused by the light ray only intersecting the cylinder once
}

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
	const t_point	point = {
		.pos = scene->camera.pos + ray * t,
		.colour = saved->color,
		.cam_ray = ray,
		.light_ray = vect3_normalize(point.pos, scene->light.pos),
		.normal = get_normal(point.pos, saved) * (double)saved->inside,
		.light_dist = vect3_abs(point.pos - scene->light.pos)
	};
	t_intersect		intersects;
	t_object		*objs;

	objs = scene->objs;
	while (objs)
	{
		intersects = get_intersects(objs, point.pos, scene->light.pos);
		// if (objs->type == CYLINDER)
		// 	printf("intersects with cylinder at (%f, %f)\n", intersects.t1, intersects.t2);
		if (check_intersects(intersects, point.light_dist))
			return (get_int_rgba(
					get_ambient(saved->color, scene->amlight.colour)));
		objs = objs->next;
	}
	return (get_phong(point, scene));
}
