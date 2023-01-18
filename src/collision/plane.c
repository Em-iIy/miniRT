/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 17:37:04 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/18 16:54:35 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

/*
plane = (point - p_o) * n = 0
ray   = point = r_o + t * d
t = ((p_o - r_o) * n) / (d * n)
*/

static t_double_intersect	create_return(double close, double far)
{
	t_double_intersect	ret;

	ret.close = close;
	ret.far = far;
	return (ret);
}

t_double_intersect	plane_collision(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n)
{
	const double	denominator = vect3_dot_product(d, n);
	double			value;

	if (denominator == 0)
		return (create_return(-1, -1));
	else
	{
		value = vect3_dot_product(vect3_substract(r_o, p_o), n) / denominator;
		return (create_return(value, value));
	}
}
