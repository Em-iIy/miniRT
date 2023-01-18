/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:37:29 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/18 18:10:56 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdbool.h>
#include <math.h>

#include <stdio.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	get_shadow(int rgba, double intensity)
{
	return (get_rgba((rgba >> 24) * intensity, (rgba >> 16) * intensity, (rgba >> 8) * intensity, 255));
}

int	get_pixel_colour(t_vect3 ray, t_scene *scene, int colour, double t)
{
	t_double_intersect	sphere_intersect;
	t_vect3				start;
	t_object			*objs;
	double				colides;
	double 				test;
	double				dist;

	objs = scene->objs;
	start = vect3_add(scene->camera.pos, vect3_multiply(ray, t));
	dist = vect3_abs(vect3_substract(start, scene->light.pos));
	//printf("t = %f\t", t);
	//vect3_print(start);
	while (objs)
	{
		if (objs->type == SPHERE)
		{
			sphere_intersect = sphere_collision(start, vect3_normalize(start, scene->light.pos), objs->coords, objs->radius);
			//printf("colides here %f and here %f\n", sphere_intersect.close, sphere_intersect.far);
			if ((sphere_intersect.close > 0.0001 || sphere_intersect.far > 0.0001) && (sphere_intersect.close < dist || sphere_intersect.far < dist))
				colides = 1;
			else
				colides = -1;
		}
		//else if (objs->type == PLANE)
			//colides = plane_collision(start, scene->light.pos, objs->coords, objs->orientation);
		if (colides > 0)
			return (get_shadow(colour, scene->amlight.brightness));
		objs = objs->next;
	}
	return (colour);
}
