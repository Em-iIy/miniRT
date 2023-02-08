/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 14:15:48 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/02/08 18:59:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

static t_vect3	get_diffuse(t_vect3 normal, t_vect3 l_dir, t_vect3 colour, t_vect3 light)
{
	double	d;

	d = vect3_dot(normal, l_dir);
	if (d < 0)
		d *= -1;
	return (light * colour * d);
}

static t_vect3	get_reflection(t_vect3 normal, t_vect3 l_dir)
{
	return (l_dir - vect3_dot(normal, l_dir) * 2 * normal);
}

static t_vect3	get_specular(t_scene *scene, t_vect3 view, t_vect3 normal, t_vect3 l_dir, t_vect3 colour)
{
	double	d;

	d = fmax(vect3_dot(view, get_reflection(normal, l_dir)), 0.0);
	return (scene->light.colour * pow(d, 32));
}

t_vect3	get_ambient(t_vect3 colour_obj, t_vect3 colour_amb)
{
	return (colour_obj * colour_amb);
}

int	get_int_rgba(t_vect3 c)
{
	const int	r = (int)(fmin(c[0], 1.0) * 255);
	const int	g = (int)(fmin(c[1], 1.0) * 255);
	const int	b = (int)(fmin(c[2], 1.0) * 255);

	return (r << 24 | g << 16 | b << 8 | 255);
}
//make struct for pixel properties
int	get_light(t_vect3 l_dir, t_vect3 normal, t_vect3 colour, t_scene *scene, t_vect3 ray)
{
	const t_vect3	diffuse = get_diffuse(normal, l_dir, colour, scene->light.colour);
	const t_vect3	ambient = get_ambient(colour, scene->amlight.colour);
	const t_vect3	spec = get_specular(scene, ray, normal, l_dir, colour);

	return (get_int_rgba(diffuse + ambient + spec));
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
