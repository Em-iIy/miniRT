/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:05 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/21 16:17:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"
#include <math.h>

static double	get_t(t_object *obj, t_vect3 cam, t_vect3 ray)
{
	if (obj->type == SPHERE)
		return (sphere_coli(cam, ray, obj->pos, obj->radius));
	else if (obj->type == PLANE)
		return (plane_coli(cam, ray, obj->pos, obj->orient));
	else if (obj->type == CYLINDER)
		return (cylinder_coli(ray, cam, obj));
	else if (obj->type == CIRCLE)
		return (circle_coli(ray, cam, obj));
	return (0);
}

int	get_collision(t_scene *scene, t_vect3 ray)
{
	t_object	*objs;
	t_object	*saved_obj;
	double		temp;
	double		t;

	objs = scene->objs;
	t = INFINITY;
	while (objs)
	{
		temp = get_t(objs, scene->camera.pos, ray);
		if (temp > 0.00001 && temp < t)
		{
			t = temp;
			saved_obj = objs;
		}
		objs = objs->next;
	}
	if (t == INFINITY)
		return (255);
	return (get_pixel_color(ray, scene, saved_obj, t));
}
