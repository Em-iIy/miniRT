/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:48:51 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/26 15:10:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "vect3_math.h"
#include "scene.h"
#include "colour.h"
#include <stdlib.h>

t_object	*obj_sp(t_object *obj, double diameter)
{
	obj->type = SPHERE;
	obj->radius = diameter / 2;
	return (obj);
}

t_object	*obj_pl(t_object *obj, t_vect3 orientation)
{
	obj->type = PLANE;
	obj->orient = vect3_normalize(vect3_0(), orientation);
	return (obj);
}

static t_object	*obj_cylinder(t_object *obj, t_vect3 orientation, \
	double length, double diameter)
{
	obj->type = CYLINDER;
	obj->orient = vect3_normalize(vect3_0(), orientation);
	//vect3_print("cyl", obj->orient);
	//printf("\n");
	obj->lenght = length;
	obj->diameter = diameter;
	obj->radius = diameter / 2;
	return (obj);
}

void	obj_cy(t_object **objs, t_vect3 orientation, \
	double length, double diameter)
{
	t_object	*temp;

	*objs = obj_cylinder(*objs, orientation, length, diameter);
	temp = obj_new((*objs)->pos, (*objs)->color);
	temp->type = CIRCLE;
	temp->radius = diameter / 2;
	temp->orient = orientation * -1;
	obj_add_front(objs, temp);
	temp = obj_new((*objs)->pos + orientation * length, (*objs)->color);
	temp->type = CIRCLE;
	temp->radius = diameter / 2;
	temp->orient = orientation;
	obj_add_front(objs, temp);
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
			temp = sphere_collision(scene->camera.pos, ray, objs->pos, objs->radius);
		else if (objs->type == PLANE)
			temp = plane_collision(scene->camera.pos, ray, objs->pos, objs->orient);
		else if (objs->type == CYLINDER)
			temp = cyl_collision(ray, scene->camera.pos, objs);
		else if (objs->type == CIRCLE)
			temp = circle_collision(ray, scene->camera.pos, objs);
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
