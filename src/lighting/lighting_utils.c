/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:15:48 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/16 18:46:28 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <math.h>

t_vect3	get_ambient(t_vect3 colour_amb)
{
	return (colour_amb * 0.2);
}

unsigned int	get_int_rgba(t_vect3 c)
{
	const unsigned int	r = fmin(c[0], 1.0) * 255;
	const unsigned int	g = fmin(c[1], 1.0) * 255;
	const unsigned int	b = fmin(c[2], 1.0) * 255;

	return (r << 24 | g << 16 | b << 8 | 255);
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
