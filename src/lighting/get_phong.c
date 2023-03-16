/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_phong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:07:44 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 19:24:33 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"
#include <math.h>

static t_vect3	get_diffuse(t_point p, t_vect3 l_colour)
{
	double	d;

	d = vect3_dot(p.normal, p.light_ray);
	if (d < 0)
		d = 0;
	return (l_colour * d * 0.4);
}

static t_vect3	get_reflection(t_vect3 normal, t_vect3 l_dir)
{
	return (l_dir - vect3_dot(normal, l_dir) * 2 * normal);
}

static t_vect3	get_specular(t_scene *scene, t_point p)
{
	double	d;

	d = fmax(vect3_dot(p.cam_ray, get_reflection(p.normal, p.light_ray)), 0.0);
	return (scene->light.colour * pow(d, 4) * 0.4);
}

t_vect3	get_phong(t_point p, t_scene *scene)
{
	const t_vect3	diffuse = get_diffuse(p, scene->light.colour);
	const t_vect3	spec = get_specular(scene, p);

	return (spec + diffuse);
}
