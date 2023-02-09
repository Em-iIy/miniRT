/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:24:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/02/09 15:59:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "scene.h"

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

void	check_inside(t_object *objs, t_vect3 cam_pos)
{
	while (objs)
	{
		if (objs->type == SPHERE)
			inside_sphere(objs, cam_pos);
		else if (objs->type == PLANE || objs->type == CIRCLE)
			inside_plane(objs, cam_pos);
		objs = objs->next;
	}
}
