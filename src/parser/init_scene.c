/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:40:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/12 15:02:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene_elements.h"
#include "get_colour.h"
#include <stdlib.h>

void	test_scene(t_scene *scene)
{
	scene->objs = NULL;
	obj_add_front(&scene->objs, obj_sp(obj_new(vect3(501, 500, 20), get_rgba(255, 0, 0, 255)), 3));
	//obj_add_front(&scene->objs, obj_sp(obj_new(vect3(500, 501, 21), get_rgba(0, 255, 0, 255)), 3));
	//obj_add_front(&scene->objs, obj_sp(obj_new(vect3(490, 510, 19), get_rgba(255, 255, 255, 255)), 1));
	obj_add_front(&scene->objs, obj_pl(obj_new(vect3(0, 0, 0), get_rgba(120, 100, 100, 255)), vect3(0, 1, 0)));
	scene->camera = new_camera(vect3(500, 500, 0), vect3(1, 0, 0), 90);
	scene->light = new_light(vect3(501, 490, 20), 0.8, 0xFFFFFFFF);
	scene->amlight = new_amblight(0.2, 0xFFFFFFFF);
}

void	init_scene(char	*infile, t_scene *scene)
{
	test_scene(scene);
	(void)infile;
}
