/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:09:51 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/26 09:59:51 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include <fcntl.h>
#include <stdlib.h>

static void	check_file_ext(char *infile)
{
	const size_t	len = ft_strlen(infile);

	if (len < 3)
		error_msg_exit("Invalid file name format\n", EXIT_FAILURE);
	else if (ft_strncmp(&infile[len - 3], ".rt", 3) != 0)
		error_msg_exit("Invalid file name format\n", EXIT_FAILURE);
}

int	parse_file_name(char *infile)
{
	int	fd;

	if (!infile)
		return (-1);
	check_file_ext(infile);
	fd = open(infile, O_RDONLY);
	if (fd == -1)
		perror_msg_exit("minirt: read", EXIT_FAILURE);
	return (fd);
}
