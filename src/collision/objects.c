/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:48:51 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/20 19:00:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "vect3_math.h"
#include "scene.h"
#include "colour.h"
#include <stdlib.h>

t_object	*obj_sp(t_object *obj, double radius)
{
	obj->type = SPHERE;
	obj->radius = radius;
	return (obj);
}

t_object	*obj_pl(t_object *obj, t_vect3 orientation)
{
	obj->type = PLANE;
	obj->orientation = orientation;
	return (obj);
}

t_object	*obj_cy(t_object *obj, t_vect3 orientation, \
	double length, double diameter)
{
	obj->type = CYLINDER;
	obj->orientation = orientation;
	obj->lenght = length;
	obj->diameter = diameter;
	return (obj);
}

int	get_collision(void *void_scene, t_vect3 ray)
{
	t_object			*objs;
	t_object			*saved_obj;
	t_scene				*scene;
	t_double_intersect	temp;
	double				t;
	double				temp_t;
	int					colour;

	colour = 255;
	scene = (t_scene *)void_scene;
	objs = scene->objs;
	t = -1;
	while (objs)
	{
		if (objs->type == SPHERE)
			temp = sphere_collision(scene->camera.pos, ray, objs->coords, objs->radius);
		else if (objs->type == PLANE)
			temp = plane_collision(scene->camera.pos, ray, objs->coords, objs->orientation);
		if (temp.t1 < temp.t2)
			temp_t = temp.t1;
		else
			temp_t = temp.t2;
		if (temp_t > 0 && (t < 0 || temp_t < t))
		{
			colour = objs->color;
			t = temp_t;
			saved_obj = objs;
		}
		objs = objs->next;
	}
	if (t < 0)
		return (255);
	return (get_pixel_colour(ray, scene, saved_obj, t));
}
