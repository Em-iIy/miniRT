/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 14:58:51 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/14 15:54:14 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

#define DIST 1

t_vect3	cast_ray(t_scene scene, double x, double y)
{
	const double	step = DIST * tan((scene.camera.fov / 2) * (M_PI / 180));
	t_vect3			p1;
	t_vect3			p2;
	t_vect3			ret;

	p1 = scene.camera.pos + scene.camera.orient
		* DIST - scene.camera.right * step;
	p2 = p1 + scene.camera.right * x / WIDTH * 2 * step;
	ret = p2 + scene.camera.up * y / HEIGHT * 2 * step;
	return (vect3_normalize(scene.camera.pos, ret));
}
