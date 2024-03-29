/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 18:00:51 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
(-b-+sqrt(b^2-4ac))/2a where:
a = d^2 = 		vect3_dot(d, d)
b = 2vd =		2 * vect3_dot(v, d)
c = v^2-r^2 = 	vect3_dot(v, v) - r * r

sphere_coli(scene->camera.pos(o), ray(d), objs->pos(c), objs->radius(r));
*/
double	sphere_coli(t_vect3 o, t_vect3 d, t_vect3 c, double r)
{
	const t_vect3	v = o - c;

	return (quadr_form(vect3_dot(d, d), 2 * vect3_dot(v, d), \
		vect3_dot(v, v) - (r * r)));
}
