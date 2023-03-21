/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:24:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/21 12:49:18 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "error.h"

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
	const t_vect3	pd = cam_pos - cyl->pos;
	const double	dot = vect3_dot(pd, d);

	(void)light_pos;
	if (vect3_dot(pd, pd) - dot * dot
		/ (cyl->lenght * cyl->lenght) < cyl->radius * cyl->radius)
		cyl->inside = -1;
}

void	check_inside(t_object *objs, t_vect3 cam_pos, t_vect3 light_pos)
{
	while (objs)
	{
		if (objs->type == SPHERE)
			inside_sphere(objs, cam_pos, light_pos);
		else if (objs->type == PLANE || objs->type == CIRCLE)
			inside_plane(objs, cam_pos, light_pos);
		else if (objs->type == CYLINDER)
			inside_cyl(objs, cam_pos, light_pos);
		objs = objs->next;
	}
}
