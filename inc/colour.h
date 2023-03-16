/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:01:04 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/16 18:55:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

# include "scene.h"

unsigned int	get_int_rgba(t_vect3 c);
t_vect3			get_phong(t_point p, t_scene *scene);
t_vect3			get_normal(t_vect3 start, t_object *saved);
int				get_pixel_color(t_vect3 ray, t_scene *scene, t_object *saved, \
	double t);
t_vect3			get_ambient(t_vect3 colour_amb);

#endif
