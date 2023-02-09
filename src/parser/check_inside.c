/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:24:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/02/09 17:19:46 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "scene.h"
#include <math.h>

static void	inside_sphere(t_object *sphere, t_vect3 cam_pos)
{
	if (vect3_abs(sphere->pos - cam_pos) < sphere->radius)
		sphere->inside = -1;
}

static void	inside_plane(t_object *plane, t_vect3 cam_pos)
{
	if (vect3_dot(cam_pos - plane->pos, plane->orient) < 0)
		plane->inside = -1;
}

static void	inside_cyl(t_object *cyl, t_vect3 cam_pos)
{
	const t_vect3	d = cyl->orient * cyl->lenght;
	const t_vect3	pd = cam_pos - cyl->pos;
	const double	dot = vect3_dot(pd, d);

	if (vect3_dot(pd, pd) - dot * dot / (cyl->lenght * cyl->lenght) < cyl->radius * cyl->radius)
		cyl->inside = -1;
	// if (vect3_abs((cam_pos - cyl->pos) * d) / vect3_abs(d) < cyl->radius)
}

void	check_inside(t_object *objs, t_vect3 cam_pos)
{
	while (objs)
	{
		if (objs->type == SPHERE)
			inside_sphere(objs, cam_pos);
		else if (objs->type == PLANE || objs->type == CIRCLE)
			inside_plane(objs, cam_pos);
		else if (objs->type == CYLINDER)
			inside_cyl(objs, cam_pos);
		objs = objs->next;
	}
}
