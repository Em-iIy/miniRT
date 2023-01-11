/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:06:03 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/11 14:10:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov)
{
	t_camera	camera;

	camera.pos = pos;
	camera.orient = orient;
	camera.fov = fov;
	return (camera);
}
