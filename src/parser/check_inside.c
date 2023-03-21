/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:24:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:50 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "error.h"
#include <math.h>

static void	inside_sphere(t_object *sphere, t_vect3 cam_pos, t_vect3 light_pos)
{
	if (vect3_abs(sphere->pos - light_pos) == sphere->radius)
		error_msg_exit("Light source exactly on sphere\n", 1);
	if (vect3_abs(sphere->pos - cam_pos) < sphere->radius)
		sphere->inside = -1;
}

static void	inside_plane(t_object *plane, t_vect3 cam_pos, t_vect3 light_pos)
{
	if (vect3_dot(light_pos - plane->pos, plane->orient) == 0)
		error_msg_exit("Light source exactly on plane\n", 1);
	if (vect3_dot(cam_pos - plane->pos, plane->orient) < 0)
		plane->inside = -1;
}

static void	inside_cyl(t_object *cyl, t_vect3 cam_pos, t_vect3 light_pos)
{
	const t_vect3	d = cyl->orient * cyl->lenght;
	t_vect3			pd;
	double			dot;

	pd = light_pos - cyl->pos;
	dot = vect3_dot(pd, d);
	if (vect3_dot(pd, pd) - dot * dot
		/ (cyl->lenght * cyl->lenght) == cyl->radius * cyl->radius
		&& vect3_dot(light_pos - cyl->pos, cyl->orient) > 0
		&& vect3_dot(light_pos - (cyl->pos + cyl->orient * cyl->lenght),
			-cyl->orient) > 0)
		error_msg_exit("Light source exactly on cylinder\n", 1);
	pd = cam_pos - cyl->pos;
	dot = vect3_dot(pd, d);
	if (vect3_dot(pd, pd) - dot * dot
		/ (cyl->lenght * cyl->lenght) < cyl->radius * cyl->radius)
		cyl->inside = -1;
}

static void	inside_circle(t_object *c, t_vect3 cam_pos, t_vect3 light_pos)
{
	if (sqrt(pow(light_pos[0] - c->pos[0], 2) + pow(light_pos[1] - c->pos[1], 2)
			+ pow(light_pos[2] - c->pos[2], 2)) <= c->radius && \
			vect3_dot(light_pos - c->pos, c->orient) == 0)
		error_msg_exit("Light source exactly on cylinder\n", 1);
	if (vect3_dot(cam_pos - c->pos, c->orient) < 0)
		c->inside = -1;
}

void	check_inside(t_object *objs, t_vect3 cam_pos, t_vect3 light_pos)
{
	while (objs)
	{
		if (objs->type == SPHERE)
			inside_sphere(objs, cam_pos, light_pos);
		else if (objs->type == CIRCLE)
			inside_circle(objs, cam_pos, light_pos);
		else if (objs->type == PLANE)
			inside_plane(objs, cam_pos, light_pos);
		else if (objs->type == CYLINDER)
			inside_cyl(objs, cam_pos, light_pos);
		objs = objs->next;
	}
}
