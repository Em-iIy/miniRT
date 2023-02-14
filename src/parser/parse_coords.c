/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_coords.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 13:06:21 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/14 16:01:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "error.h"

t_vect3	parse_coords(char *str)
{
	char	**tmp;
	int		i;
	t_vect3	ret;

	tmp = ft_split(str, ',');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		error_msg_exit("Parse error: invalid vector\n", EXIT_FAILURE);
	ret = (t_vect3){
		ft_atod(tmp[0]),
		ft_atod(tmp[1]),
		ft_atod(tmp[2])
	};
	ft_free_all(tmp);
	return (ret);
}
