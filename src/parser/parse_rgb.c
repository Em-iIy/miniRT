/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rgb.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 11:15:11 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/08 16:59:16 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "colour.h"

typedef int	t_rgb __attribute__((vector_size(16)));

static bool	is_rgb(int n)
{
	return (n >= 0 && n <= 255);
}

t_vect3	parse_vect_rgb(char *str)
{
	char	**tmp;
	int		ret;
	t_vect3	rgb;
	int		i;

	tmp = ft_split(str, ',');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		error_msg_exit("Parse error: invalid rgb\n", EXIT_FAILURE);
	i = 0;
	while (tmp[i])
	{
		if (!ft_check_valid_atoi(&ret, tmp[i]) || !is_rgb(ret))
			error_msg_exit("Parse error: invalid rgb\n", EXIT_FAILURE);
		rgb[i] = ret;
		i++;
	}
	ft_free_all(tmp);
	return (rgb);
}
