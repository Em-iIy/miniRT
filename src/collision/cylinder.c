/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 17:43:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/20 18:26:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

/*
x = subtraction(camera_coords, cylinder_coords)
------------------------------------------------------
(-b-+sqrt(b^2-4ac))/2a where:

a = dot_product(ray, ray) - dot_product(ray, cylinder_dir)

b = 2 * do_product(ray, x)

c = dot_product(x, x) - dot_product(x, cylinder_dir)^2 - radius^2

*/

t_double_intersect	cylinder_collision(t_vect3 ray, t_vect3 cam, t_object cylinder)
{
	const t_vect3	x = vect3_substract(cam, cylinder.coords);

	return (quadr_form(vect3_dot_product(x, x), 2 * vect3_dot_product(ray, x), vect3_dot_product(x, x) - pow(vect3_dot_product(x, cylinder.orientation), 2) - pow(cylinder.radius, 2)));
}
