/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 14:39:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/27 14:32:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

t_intersect	circle_coli(t_vect3 ray, t_vect3 pos, t_object *c)
{
	t_intersect	colides;
	t_vect3		point;

	colides = plane_coli(pos, ray, c->pos, c->orient);
	point = pos + ray * colides.t1;
	if (sqrt(pow(point[0] - c->pos[0], 2) + pow(point[1] - c->pos[1], 2)
			+ pow(point[2] - c->pos[2], 2)) > c->radius)
		return (create_return(-1, -1));
	return (colides);
}
