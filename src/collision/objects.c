/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:48:51 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/27 20:07:00 by fpurdom       ########   odam.nl         */
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
