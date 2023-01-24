/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:06:03 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/24 16:10:09 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov)
{
	t_camera	camera;

	camera.pos = pos;
	camera.orient = vect3_normalize((t_vect3){0, 0, 0}, orient);
	camera.fov = fov;
	camera.right = vect3_normalize((t_vect3){0, 0, 0}, (t_vect3){orient[2], 0, -1 * orient[0]});
	camera.up = vect3_normalize((t_vect3){0, 0, 0}, vect3_cross_product(orient, camera.right));
	camera.dist = (WIDTH / 2) / tan(((fov / 2) * (M_PI / 180)) * (M_PI / 180));
	return (camera);
}
