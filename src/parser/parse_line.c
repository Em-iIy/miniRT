/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_line.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 10:13:20 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/14 16:03:36 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "parse.h"

void	parse_line(t_scene *scene, char *line)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!ft_strncmp(tmp[0], "A", 2))
		parse_amblight(&(scene->amlight), tmp);
	else if (!ft_strncmp(tmp[0], "C", 2))
		parse_camera(&(scene->camera), tmp);
	else if (!ft_strncmp(tmp[0], "L", 2))
		parse_light(&(scene->light), tmp);
	else if (!ft_strncmp(tmp[0], "sp", 3))
		parse_sphere(&scene->objs, tmp);
	else if (!ft_strncmp(tmp[0], "pl", 3))
		parse_plane(&scene->objs, tmp);
	else if (!ft_strncmp(tmp[0], "cy", 3))
		parse_cyl(&scene->objs, tmp);
	else
		error_msg_exit("Invalid object identifier\n", EXIT_FAILURE);
	ft_free_all(tmp);
	free(line);
}
