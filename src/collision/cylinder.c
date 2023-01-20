/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 17:43:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/20 20:05:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

/*
x = subtraction(camera_coords, cylinder_coords)
------------------------------------------------------
(-b-+sqrt(b^2-4ac))/2a where:

a = dot_product(ray, ray) - dot_product(ray, cylinder_dir)

b = 2 * (do_product(ray, x) - dot_product(ray, cylinder_dir) * dot_product(x, cylinder_dir)

c = dot_product(x, x) - dot_product(x, cylinder_dir)^2 - radius^2

*/

t_double_intersect	cylinder_collision(t_vect3 ray, t_vect3 cam_pos, t_object cylinder)
{
	const t_vect3		x = vect3_substract(cam_pos, cylinder.coords);
	const double		a = vect3_dot_product(ray, ray) - pow(vect3_dot_product(ray, cylinder.orientation), 2);
	const double		b = 2 * (vect3_dot_product(ray, x) - vect3_dot_product(ray, cylinder.orientation) * vect3_dot_product(x, cylinder.orientation));
	const double		c = vect3_dot_product(x, x) - pow(vect3_dot_product(x, cylinder.orientation), 2) - pow(cylinder.radius, 2);
	t_double_intersect	intersects;

	intersects = quadr_form(a, b ,c);
	return (intersects);
}
