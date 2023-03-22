/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:58:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/22 16:32:35 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vect3	cast_ray(t_scene scene, double x, double y)
{
	t_vect3			p1;
	t_vect3			p2;
	t_vect3			ret;

	p1 = scene.camera.pos + scene.camera.orient - scene.camera.right * \
		scene.camera.step;
	p2 = p1 + scene.camera.right * (x + 0.5) / WIDTH * 2 * scene.camera.step;
	ret = p2 + scene.camera.up * (y + 0.5) / HEIGHT * 2 * scene.camera.step_up;
	return (vect3_normalize(scene.camera.pos, ret));
}
