/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_elements.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:06:44 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/25 17:06:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_ELEMENTS_H
# define SCENE_ELEMENTS_H

# include "scene.h"

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov);
t_light		new_light(t_vect3 pos, double brightness, int colour);
t_amblight	new_amblight(double brightness, int colour);

#endif
