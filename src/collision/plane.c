/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:37:04 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 18:26:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
plane = (point - p_o) * n = 0
ray   = point = r_o + t * d
t = ((p_o - r_o) * n) / (d * n)
plane_coli(scene->camera.pos(r_o), ray(d), objs->pos(p_o), objs->orient(n))
*/

double	plane_coli(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n)
{
	const double	denominator = vect3_dot(d, n);

	if (denominator == 0)
		return (0);
	return (vect3_dot(p_o - r_o, n) / denominator);
}
