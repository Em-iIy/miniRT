/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cyl->c                                  	        :+:    :+:         	  */
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
x = subtraction(camera_pos, cyl_pos)
------------------------------------------------------
(-b-+sqrt(b^2-4ac))/2a where:

a = dot_product(ray, ray) - dot_product(ray, cyl_dir)

b = 2 * (dot_product(ray, x) - dot_product(ray, cyl_dir) * dot_product(x, cyl_dir)

c = dot_product(x, x) - dot_product(x, cyl_dir)^2 - radius^2

*/

t_double_intersect	cyl_collision(t_vect3 ray, t_vect3 pos, t_object *cyl)
{
	const t_vect3		x = pos - cyl->pos;
	t_double_intersect	tube;
	t_double_intersect	circles;
	t_double_intersect	m;

	tube = quadr_form(vect3_dot_product(ray, ray) - pow(vect3_dot_product(ray, cyl->orient), 2), 2 * (vect3_dot_product(ray, x) - vect3_dot_product(ray, cyl->orient) * vect3_dot_product(x, cyl->orient)), vect3_dot_product(x, x) - pow(vect3_dot_product(x, cyl->orient), 2) - pow(cyl->radius, 2));
	if (tube.t1)
	{
		m.t1 = vect3_dot_product(ray, cyl->orient * tube.t1) + vect3_dot_product(x, cyl->orient);
		if (m.t1 < 0 || m.t1 > cyl->lenght)
			tube.t1 = -1;
	}
	if (tube.t2)
	{
		m.t2 = vect3_dot_product(ray, cyl->orient * tube.t2) + vect3_dot_product(x, cyl->orient);
		if (m.t2 < 0 || m.t2 > cyl->lenght)
			tube.t2 = -1;
	}
	// m.t2 = vect3_dot_product(ray, cyl->orient * tube.t2) + vect3_dot_product(x, cyl->orient);
	// if (m.t1 < 0 || m.t1 > cyl->lenght || (m.t2 < 0 || m.t2 > cyl->lenght))
	// 	return (create_return(-1, -1));
	return (tube);
}
