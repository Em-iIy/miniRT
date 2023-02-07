/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:01:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/02/07 16:34:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

# include "scene.h"

int		get_rgba(int r, int g, int b, int a);
int		ret_int_rgba(t_vect3 c);
int		get_shadow(int rgba, double intensity);
int		get_light(t_vect3 light_dir, t_vect3 normal, t_vect3 obj_color, t_vect3 amb, double light);
t_vect3	give_rgba(int colour);
t_vect3	get_normal(t_vect3 start, t_object *saved);
int		get_pixel_color(t_vect3 ray, t_scene *scene, t_object *saved, double t);

#endif
