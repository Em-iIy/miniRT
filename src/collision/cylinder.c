/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c->c                                  	        :+:    :+:         	  */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 17:43:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/25 13:11:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

/*
x = subtraction(camera_pos, c_pos)
------------------------------------------------------
(-b-+sqrt(b^2-4ac))/2a where:

a = dot_product(ray, ray) - dot_product(ray, c_dir)

b = 2 * (dot_product(ray, x) - dot_product(ray, c_dir) * dot_product(x, c_dir)

c = dot_product(x, x) - dot_product(x, c_dir)^2 - radius^2

*/

t_intersect	cylinder_coli(t_vect3 ray, t_vect3 pos, t_object *c)
{
	const t_vect3	x = pos - c->pos;
	t_intersect		tube;
	t_intersect		m;

	tube = quadr_form(vect3_dot(ray, ray) - pow(vect3_dot(ray, c->orient), 2),
			2 * (vect3_dot(ray, x) - vect3_dot(ray, c->orient)
				* vect3_dot(x, c->orient)), vect3_dot(x, x)
			- pow(vect3_dot(x, c->orient), 2) - pow(c->radius, 2));
	if (tube.t1)
	{
		m.t1 = vect3_dot(ray, c->orient * tube.t1) + vect3_dot(x, c->orient);
		if (m.t1 < 0 || m.t1 > c->lenght)
			tube.t1 = -1;
	}
	if (tube.t2)
	{
		m.t2 = vect3_dot(ray, c->orient * tube.t2) + vect3_dot(x, c->orient);
		if (m.t2 < 0 || m.t2 > c->lenght)
			tube.t2 = -1;
	}
	if (tube.t1 > 0.00000001 && tube.t2 < 0)
		tube.t2 = tube.t1;
	else if (tube.t2 > 0.00000001 && tube.t1 < 0)
		tube.t1 = tube.t2;
	return (tube);
}
