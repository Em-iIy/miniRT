/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:58:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/17 16:51:09 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "scene.h"
#include <math.h>

#define DIST 1

t_vect3	cast_ray(t_scene scene, double x, double y)
{
	t_vect3			p1;
	t_vect3			p2;
	t_vect3			ret;

	// p1 = vect3_substract(vect3_add(scene.camera.pos, vect3_multiply(scene.camera.orient, scene.camera.dist)), vect3_multiply(scene.camera.right, WIDTH / 2));
	// p2 = vect3_add(p1, vect3_multiply(scene.camera.right, x));
	// ret = vect3_add(p2, vect3_multiply(scene.camera.up, y));
	// printf("(%f, %f)\n", tan((scene.camera.fov / 2) * (M_PI / 180)), y / HEIGHT * 2 * DIST * tan((scene.camera.fov / 2) * (M_PI / 180)));
	p1 = vect3_substract(vect3_add(scene.camera.pos, vect3_multiply(scene.camera.orient, DIST)), vect3_multiply(scene.camera.right, DIST * tan((scene.camera.fov / 2) * (M_PI / 180))));
	p2 = vect3_add(p1, vect3_multiply(scene.camera.right, x / WIDTH * 2 * DIST * tan((scene.camera.fov / 2) * (M_PI / 180))));
	ret = vect3_add(p2, vect3_multiply(scene.camera.up, y / HEIGHT * 2 * DIST * tan((scene.camera.fov / 2) * (M_PI / 180))));
	return (vect3_normalize(scene.camera.pos, ret));
	return (ret);
}
