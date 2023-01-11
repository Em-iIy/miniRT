/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 17:37:04 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/11 13:20:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

/*
plane = (point - p_o) * n = 0
ray   = point = r_o + t * d
t = ((p_o - r_o) * n) / (d * n)
*/
double	plane_collision(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n)
{
	const double	denominator = vect3_dot_product(d, n);

	if (denominator == 0)
		return (denominator);
	else
		return (vect3_dot_product(vect3_substract(p_o, r_o), n) / denominator);
}
