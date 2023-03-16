/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:07:05 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/16 12:41:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

static t_intersect	get_t(t_object *obj, t_vect3 cam, t_vect3 ray)
{
	if (obj->type == SPHERE)
		return (sphere_coli(cam, ray, obj->pos, obj->radius));
	else if (obj->type == PLANE)
		return (plane_coli(cam, ray, obj->pos, obj->orient));
	else if (obj->type == CYLINDER)
		return (cylinder_coli(ray, cam, obj));
	else if (obj->type == CIRCLE)
		return (circle_coli(ray, cam, obj));
	return (create_return(0, 0));
}

int	get_collision(t_scene *scene, t_vect3 ray)
{
	t_object	*objs;
	t_object	*saved_obj;
	t_intersect	temp;
	double		t;

	objs = scene->objs;
	t = -1;
	while (objs)
	{
		temp = get_t(objs, scene->camera.pos, ray);
		if (temp.t1 > 0 && (temp.t2 < 0 || temp.t1 < temp.t2)
			&& temp.t1 > 0 && (t < 0 || temp.t1 < t))
			t = temp.t1;
		else if (temp.t2 > 0 && (t < 0 || temp.t2 < t))
			t = temp.t2;
		if (t == temp.t1 || t == temp.t2)
			saved_obj = objs;
		objs = objs->next;
	}
	if (t < 0)
		return (255);
	return (get_pixel_color(ray, scene, saved_obj, t));
}
