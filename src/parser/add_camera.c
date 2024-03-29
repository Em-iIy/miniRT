/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:06:03 by fpurdom           #+#    #+#             */
/*   Updated: 2023/03/22 16:32:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"
#include <math.h>

static int	parse_fov(char *str)
{
	int	ret;

	if (!ft_check_valid_atoi(&ret, str) || ret < 0 || ret > 180)
		error_msg_exit("Parse error: invalid fov\n", EXIT_FAILURE);
	return (ret);
}

t_camera	new_camera(t_vect3 pos, t_vect3 orient, int fov)
{
	t_camera	camera;

	camera.set = true;
	camera.pos = pos;
	camera.orient = vect3_normalize(vect3_0(), orient);
	camera.fov = fov;
	if (!orient[0] && !orient[2])
		camera.right = vect3(1, 0, 0);
	else
		camera.right = vect3_normalize(vect3_0(), \
			(t_vect3){orient[2], 0, -1 * orient[0]});
	if (!orient[0] && !orient[2])
		camera.up = vect3(0, 0, 1);
	else
		camera.up = vect3_normalize(vect3_0(), \
			vect3_cross_product(orient, camera.right));
	camera.step = tan((camera.fov / 2) * (M_PI / 180));
	camera.step_up = tan(((camera.fov * ((float)HEIGHT / (float)WIDTH)) / 2)
			* (M_PI / 180));
	return (camera);
}

void	parse_camera(t_camera *cam, char **line)
{
	int	i;

	i = 0;
	if (cam->set)
		error_msg_exit("Parse error: camera set multiple times\n", EXIT_FAILURE);
	while (line[i])
		i++;
	if (i != 4)
		error_msg_exit("Parse error: invalid camera\n", EXIT_FAILURE);
	*cam = new_camera(parse_coords(line[1]), \
		parse_direction(line[2]), parse_fov(line[3]));
}
