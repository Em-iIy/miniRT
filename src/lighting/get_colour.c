/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/12 15:05:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, int colour, double *t)
{
	t_vect3		start;
	t_object	*objs;
	double		colides;

	objs = scene->objs;
	start = vect3_add(scene->camera.pos, vect3_multiply(ray, *t));
	while (objs)
	{
		if (objs->type == SPHERE)
			colides = sphere_collision(start, scene->light.pos, objs->coords, objs->radius);
		//else if (objs->type == PLANE)
			//colides = plane_collision(start, scene->light.pos, objs->coords, objs->orientation);
		if (colides > 0.0000001)
		{
			printf("colides: %f\n", colides);
			vect3_print(ray);
			return (0);
		}
		objs = objs->next;
	}
	return (colour);
}
