/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:57:59 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/25 16:06:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include <math.h>
#include <stdio.h>

double	ft_atod(char *str)
{
	char	**tmp;
	int		dec;
	int		i;
	int		len;

	tmp = ft_split(str, '.');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 1 && i != 2)
		error_msg_exit("Parse error: invalid float value\n", EXIT_FAILURE);
	if (i == 1 && ft_check_valid_atoi(&dec, str))
	{
		ft_free_all(tmp);
		return (dec);
	}
	if (!ft_check_valid_atoi(&i, tmp[0]) \
		||!ft_check_valid_atoi(&dec, tmp[1]) \
		|| dec < 0)
		error_msg_exit("Parse error: invalid float value\n", EXIT_FAILURE);
	len = ft_strlen(tmp[1]);
	if (tmp[0][0] == '-')
		dec = dec * -1;
	ft_free_all(tmp);
	return (i + dec / pow(10, len));
}
