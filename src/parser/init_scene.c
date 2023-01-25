/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:40:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/25 19:59:10 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene_elements.h"
#include "colour.h"
#include <stdlib.h>

void	test_scene(t_scene *scene)
{
	scene->objs = NULL;
	obj_add_front(&scene->objs, obj_sp(obj_new(vect3(-2, 0, 2), get_rgba(255, 0, 0, 255)), 1));
	obj_add_front(&scene->objs, obj_sp(obj_new(vect3(0, 0, 2), get_rgba(255, 255, 0, 255)), 1));
	// obj_add_front(&scene->objs, obj_sp(obj_new(vect3(0, 0, 2), get_rgba(255, 255, 0, 255)), 1000));
	obj_add_front(&scene->objs, obj_sp(obj_new(vect3(2, 0, 2), get_rgba(0, 0, 255, 255)), 1));
	obj_add_front(&scene->objs, obj_cy(obj_new(vect3(4, -1, 0), get_rgba(255, 0, 0, 255)), vect3(0, 1, 0), 3, 2));
	obj_add_front(&scene->objs, obj_pl(obj_new(vect3(0, -2, 4), get_rgba(120, 100, 100, 255)), vect3(0, 1, 0)));
	obj_add_front(&scene->objs, obj_pl(obj_new(vect3(-5, 0, 0), get_rgba(120, 100, 100, 255)), vect3(1, 0, 0)));
	scene->camera = new_camera(vect3(0, 2, -10), vect3(0, -0.3, 1), 90);
	scene->light = new_light(vect3(8, 5, 0), 0.5, 0xFFFFFFFF);
	scene->amlight = new_amblight(0.1, 0xFFFFFFFF);
}

void	init_scene(char	*infile, t_scene *scene)
{
	test_scene(scene);
	(void)infile;
}
