/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:06:03 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/17 14:24:52 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov)
{
	t_camera	camera;

	camera.pos = pos;
	camera.orient = vect3_normalize(vect3(0, 0, 0), orient);
	camera.fov = fov;
	camera.right = vect3_normalize(pos, vect3_add(pos, \
		vect3(orient.z, 0, -1 * orient.x)));
	camera.up = vect3_normalize(pos, vect3_add(pos, \
		vect3_cross_product(orient, camera.right)));
	camera.dist = (WIDTH / 2) / tan(((fov / 2) * (M_PI / 180)) * (M_PI / 180));
	return (camera);
}
