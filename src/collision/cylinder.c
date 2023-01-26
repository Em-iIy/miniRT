/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cyl.c                                  	        :+:    :+:         	  */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 17:43:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/25 13:11:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

#include <stdio.h>
/*
x = subtraction(camera_pos, cyl_pos)
------------------------------------------------------
(-b-+sqrt(b^2-4ac))/2a where:

a = dot_product(ray, ray) - dot_product(ray, cyl_dir)

b = 2 * (dot_product(ray, x) - dot_product(ray, cyl_dir) * dot_product(x, cyl_dir)

c = dot_product(x, x) - dot_product(x, cyl_dir)^2 - radius^2

*/

static t_double_intersect	ret_shortest_t(t_double_intersect tube, t_double_intersect circles)
{
	if (circles.t1 < 0 && circles.t2 < 0)
		return (tube);
	if (tube.t1 < 0 && tube.t2 < 0)
		return (circles);
}

static t_double_intersect	intersects_circles(t_vect3 o, t_vect3 r, t_object c)
{
	const t_vect3		c_top = c.pos + c.orient * c.lenght;
	t_double_intersect	colides;
	t_vect3				point;

	colides.t1 = plane_collision(o, r, c.pos, c.orient * -1).t1;
	colides.t2 = plane_collision(o, r, c_top, c.orient).t1;
	point = o + r * colides.t1;
	if (sqrt(pow(point[0] - c.pos[0], 2) + pow(point[1] - c.pos[1], 2)
		+ pow(point[2] - c.pos[2], 2)) > c.radius)
		colides.t1 = -1;
	point = o + r * colides.t2;
	if (sqrt(pow(point[0] - c_top[0], 2) + pow(point[1] - c_top[1], 2)
		+ pow(point[2] - c_top[2], 2)) > c.radius)
		colides.t2 = -1;
	return (colides);
}

static t_double_intersect	calculate_m(t_vect3 ray, t_vect3 dir, t_vect3 x, t_double_intersect t)
{
	t_double_intersect m;

	m.t1 = vect3_dot_product(ray, dir * t.t1) + vect3_dot_product(x, dir);
	m.t2 = vect3_dot_product(ray, dir * t.t2) + vect3_dot_product(x, dir);
	return (m);
}

t_double_intersect	cyl_collision(t_vect3 ray, t_vect3 pos, t_object cyl)
{
	const t_vect3		x = pos - cyl.pos;
	t_double_intersect	tube;
	t_double_intersect	circles;
	t_double_intersect	m;

	tube = quadr_form(vect3_dot_product(ray, ray) - pow(vect3_dot_product(ray, cyl.orient), 2), 2 * (vect3_dot_product(ray, x) - vect3_dot_product(ray, cyl.orient) * vect3_dot_product(x, cyl.orient)), vect3_dot_product(x, x) - pow(vect3_dot_product(x, cyl.orient), 2) - pow(cyl.radius, 2));
	circles = intersects_circles(pos, ray, cyl);
	m = calculate_m(ray, cyl.orient, x, tube);
	if ((m.t1 < 0 && m.t2 < 0) || (m.t1 > cyl.lenght && m.t2 > cyl.lenght))
		return (create_return(-1, -1));
	return (tube);
}
