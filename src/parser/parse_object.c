/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:17:08 by gwinnink          #+#    #+#             */
/*   Updated: 2023/02/09 15:56:50 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "objects.h"
#include "parse.h"
#include <stdlib.h>

void	parse_sphere(t_object **objs, char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != 4)
		error_msg_exit("Parse error: invalid sphere\n", EXIT_FAILURE);
	obj_add_front(objs, obj_sp(obj_new(parse_coords(line[1]), \
		parse_vect_rgb(line[3])), ft_atod(line[2])));
}

void	parse_plane(t_object **objs, char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != 4)
		error_msg_exit("Parse error: invalid plane\n", EXIT_FAILURE);
	obj_add_front(objs, obj_pl(obj_new(parse_coords(line[1]), \
		parse_vect_rgb(line[3])), parse_direction(line[2])));
}

/*
0  1             2           3    4     5
id coords        direction   rad  len   rgb
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
*/
void	parse_cyl(t_object **objs, char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != 6)
		error_msg_exit("Parse error: invalid plane\n", EXIT_FAILURE);
	obj_add_front(objs, obj_new(parse_coords(line[1]), \
		parse_vect_rgb(line[5])));
	obj_cy(objs, parse_direction(line[2]), ft_atod(line[4]), ft_atod(line[3]));
}
