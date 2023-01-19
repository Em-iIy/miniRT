/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_colour.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:01:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/19 16:54:46 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_COLOUR_H
# define GET_COLOUR_H

# include "objects.h"
# include "vect3_math.h"

int	get_rgba(int r, int g, int b, int a);
int	get_pixel_colour(t_vect3 ray, t_scene *scene, int colour, double t);

#endif
