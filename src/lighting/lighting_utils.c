/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 14:15:48 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/02/07 16:31:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_vect3	give_rgba(int colour)
{
	return ((t_vect3){
		colour >> 24 & 255,
		colour >> 16 & 255,
		colour >> 8 & 255
	});
}

int	get_shadow(int rgba, double intensity)
{
	return (get_rgba((rgba >> 24 & 255) * intensity, (rgba >> 16 & 255)
			* intensity, (rgba >> 8 & 255) * intensity, 255));
}

int	ret_int_rgba(t_vect3 c)
{
	return ((int)(c[0] * 255) << 24 | (int)(c[1] * 255) << 16 | (int)(c[2] * 255) << 8 | 255);
}

int	get_light(t_vect3 light_dir, t_vect3 normal, t_vect3 obj_color, t_vect3 amb, double light)
{
	float	d;
	//t_vect3	rgba;
	//t_vect3	ret;

	d = vect3_dot(normal, light_dir);
	if (d < 0)
		d = 0;
	return (ret_int_rgba(obj_color * (amb + (light * d))));
	// rgba = give_rgba(colour) * d;
	// ret[0] = sqrt((pow(rgba[0], 2) + pow(shadow >> 24 & 255, 2)) / 2);
	// if (ret[0] < (shadow >> 24 & 255))
	// 	ret[0] = shadow >> 24 & 255;
	// ret[1] = sqrt((pow(rgba[1], 2) + pow(shadow >> 16 & 255, 2)) / 2);
	// if (ret[1] < (shadow >> 16 & 255))
	// 	ret[1] = shadow >> 16 & 255;
	// ret[2] = sqrt((pow(rgba[2], 2) + pow(shadow >> 8 & 255, 2)) / 2);
	// if (ret[2] < (shadow >> 8 & 255))
	// 	ret[2] = shadow >> 8 & 255;
	// return (get_rgba(ret[0], ret[1], ret[2], 255));
}

t_vect3	get_normal(t_vect3 start, t_object *saved)
{
	if (saved->type == SPHERE)
		return (vect3_normalize(saved->pos, start));
	if (saved->type == CYLINDER)
		return (vect3_normalize(saved->pos
				+ (vect3_dot(start - saved->pos, saved->orient)
					* saved->orient), start));
	return (saved->orient);
}
