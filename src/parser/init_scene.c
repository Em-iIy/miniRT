/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:40:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/26 15:06:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "parse.h"
#include <stdlib.h>
#include <unistd.h>

void	init_scene(char	*infile, t_scene *scene)
{
	const int	fd = parse_file_name(infile);
	char		*line;

	scene->camera.set = false;
	scene->light.set = false;
	scene->amlight.set = false;
	scene->objs = NULL;
	if (fd < 0)
		error_msg_exit("Filename error: how you get here lol\n", EXIT_FAILURE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line != '\n' && *line != '#')
			parse_line(scene, ft_strtrim(line, "\n"));
		free(line);
	}
	close(fd);
	if (!scene->camera.set || !scene->amlight.set || !scene->light.set)
		error_msg_exit("scene error: missing camera or lights\n", EXIT_FAILURE);
}
