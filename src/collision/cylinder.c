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

double	cylinder_coli(t_vect3 ray, t_vect3 pos, t_object *c)
{
	const t_vect3	x = pos - c->pos;
	double			t;
	double			m;

	t = quadr_form(vect3_dot(ray, ray) - pow(vect3_dot(ray, c->orient), 2),
			2 * (vect3_dot(ray, x) - vect3_dot(ray, c->orient)
				* vect3_dot(x, c->orient)), vect3_dot(x, x)
			- pow(vect3_dot(x, c->orient), 2) - pow(c->radius, 2));
	if (t > 0.0000001)
	{
		m = vect3_dot(ray, c->orient * t) + vect3_dot(x, c->orient);
		if (m < 0 || m > c->lenght)
			t = 0;
	}
	return (t);
}
