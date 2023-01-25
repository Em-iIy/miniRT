/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:01:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/25 19:55:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

# include "scene.h"

int	get_rgba(int r, int g, int b, int a);
int	get_pixel_colour(t_vect3 ray, t_scene *scene, t_object *saved_obj, double t);

#endif
