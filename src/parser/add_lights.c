/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:51:53 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/25 17:18:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parse.h"
#include "error.h"
#include <stdlib.h>

static bool	is_valid(double d)
{
	return (d >= -1 && d <= 1);
}

t_light	new_light(t_vect3 pos, double brightness, int colour)
{
	t_light	light;

	light.set = true;
	light.pos = pos;
	if (!is_valid(brightness))
		error_msg_exit("Parse error: invalid light brightness\n", EXIT_FAILURE);
	light.brightness = brightness;
	light.colour = colour;
	return (light);
}

t_amblight	new_amblight(double brightness, int colour)
{
	t_amblight	amblight;

	amblight.set = true;
	if (!is_valid(brightness))
		error_msg_exit("Parse error: invalid alight brightness\n", EXIT_FAILURE);
	amblight.brightness = brightness;
	amblight.colour = colour;
	return (amblight);
}

void	parse_light(t_light *light, char **line)
{
	int	i;

	i = 0;
	if (light->set)
		error_msg_exit("Parse error: light set multiple times\n", EXIT_FAILURE);
	while (line[i])
		i++;
	if (i != 3)
		error_msg_exit("Parse error: invalid light\n", EXIT_FAILURE);
	*light = new_light(parse_coords(line[1]), \
		ft_atod(line[2]), 0xFFFFFFFF);
}

void	parse_amblight(t_amblight *light, char **line)
{
	int	i;

	i = 0;
	if (light->set)
		error_msg_exit("Parse error: alight set multiple times\n", EXIT_FAILURE);
	while (line[i])
		i++;
	if (i != 3)
		error_msg_exit("Parse error: invalid alight\n", EXIT_FAILURE);
	*light = new_amblight(ft_atod(line[1]), parse_rgb(line[2]));
}
