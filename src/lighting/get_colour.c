/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/14 13:23:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdbool.h>

#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, int colour, double t)
{
	t_double_intersect	sphere_intersect;
	t_vect3				start;
	t_object			*objs;
	double				colides;
	double 				test;

	objs = scene->objs;
	start = vect3_add(scene->camera.pos, vect3_multiply(ray, t));
	//printf("t = %f\t", t);
	//vect3_print(start);
	while (objs)
	{
		if (objs->type == SPHERE)
		{
			sphere_intersect = sphere_collision(scene->light.pos, start, objs->coords, objs->radius);
			//printf("colides here %f and here %f\n", sphere_intersect.close, sphere_intersect.far);
			if (sphere_intersect.close > 0 && sphere_intersect.far > 0)
				colides = 1;
			else
				colides = -1;
		}
		//else if (objs->type == PLANE)
			//colides = plane_collision(start, scene->light.pos, objs->coords, objs->orientation);
		if (colides > 0)
			return (0);
		objs = objs->next;
	}
	return (colour);
}
