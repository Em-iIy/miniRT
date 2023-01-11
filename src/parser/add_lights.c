/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_lights.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:51:53 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/11 16:01:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_light	new_light(t_vect3 pos, float brightness, int colour)
{
	t_light	light;

	light.pos = pos;
	light.brightness = brightness;
	light.colour = colour;
	return (light);
}

t_amblight	new_amblight(float brightness, int colour)
{
	t_amblight	amblight;

	amblight.brightness = brightness;
	amblight.colour = colour;
	return (amblight);
}
