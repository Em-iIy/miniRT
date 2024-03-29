/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:39:32 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/16 18:28:49 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

double	circle_coli(t_vect3 ray, t_vect3 pos, t_object *c)
{
	double	t;
	t_vect3	point;

	t = plane_coli(pos, ray, c->pos, c->orient);
	point = pos + ray * t;
	if (sqrt(pow(point[0] - c->pos[0], 2) + pow(point[1] - c->pos[1], 2)
			+ pow(point[2] - c->pos[2], 2)) > c->radius)
		return (0);
	return (t);
}
