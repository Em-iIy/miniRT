/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 14:39:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/26 15:01:10 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

t_double_intersect	circle_collision(t_vect3 ray, t_vect3 pos, t_object *c)
{
	t_double_intersect	colides;
	t_vect3				point;

	colides = plane_collision(pos, ray, c->pos, c->orient);
	point = pos + ray * colides.t1;
	if (sqrt(pow(point[0] - c->pos[0], 2) + pow(point[1] - c->pos[1], 2)
		+ pow(point[2] - c->pos[2], 2)) > c->radius)
		return (create_return(-1, -1));
	return (colides);
}
