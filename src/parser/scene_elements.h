/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_elements.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:06:44 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/11 16:01:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_ELEMENTS_H
# define SCENE_ELEMENTS_H

# include "scene.h"

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov);
t_light		new_light(t_vect3 pos, float brightness, int colour);
t_amblight	new_amblight(float brightness, int colour);

#endif
