/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_collision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 20:07:05 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/27 20:15:26 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_intersect	get_t(t_object *obj, t_vect3 cam, t_vect3 ray)
{
	t_intersect	temp;

	if (obj->type == SPHERE)
		temp = sphere_coli(cam, ray, obj->pos, obj->radius);
	else if (obj->type == PLANE)
		temp = plane_coli(cam, ray, obj->pos, obj->orient);
	else if (obj->type == CYLINDER)
		temp = cylinder_coli(ray, cam, obj);
	else if (obj->type == CIRCLE)
		temp = circle_coli(ray, cam, obj);
	return (temp);
}

int	get_collision(void *void_scene, t_vect3 ray)
{
	t_object	*objs;
	t_object	*saved_obj;
	t_scene		*scene;
	t_intersect	temp;
	double		t;

	scene = (t_scene *)void_scene;
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
	return (get_pixel_colour(ray, scene, saved_obj, t));
}
