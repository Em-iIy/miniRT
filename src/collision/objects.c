/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:48:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/11 12:14:49 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "collision.h"
#include "vect3_math.h"
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

int	get_collision(t_vect3 o, t_vect3 d, t_object *objs, double *t)
{
	double	temp;
	int		ret;

	ret = 255;
	while (objs)
	{
		if (objs->type == SPHERE)
			temp = sphere_collision(o, d, objs->coords, objs->radius);
		else if (objs->type == PLANE)
			temp = plane_collision(o, d, objs->coords, objs->orientation);
		if (temp > 0 && (*t < 0 || temp < *t))
		{
			// printf("t = %f\n", temp);
			ret = objs->color;
			*t = temp;
		}
		objs = objs->next;
	}
	return (ret);
}
