/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/24 16:00:35 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "objects.h"
#include <stdbool.h>

/*
(-b-+sqrt(b^2-4ac))/2a where:
a = d^2 = 		vect3_dot_product(d, d)
b = 2vd =		2 * vect3_dot_product(v, d)
c = v^2-r^2 = 	vect3_dot_product(v, v) - r * r
*/
t_double_intersect	sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r)
{
	const t_vect3	v = o - c;

	return (quadr_form(vect3_dot_product(d, d), 2 * vect3_dot_product(v, d), \
		vect3_dot_product(v, v) - (r * r)));
}
