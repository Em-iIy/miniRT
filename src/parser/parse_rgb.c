/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:15:11 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/17 14:08:02 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "colour.h"

static bool	is_rgb(int n)
{
	return (n >= 0 && n <= 255);
}

static int	hex_to_int(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	if (ft_isdigit(c))
		return (c - 48);
	error_msg_exit("Parse error: invalid hex rgb\n", EXIT_FAILURE);
	return (0);
}

static t_vect3	parse_hex_rgb(char *str)
{
	t_vect3	ret;

	ret = vect3_0();
	if (ft_strlen(str) != 7)
		error_msg_exit("Parse error: invalid hex rgb\n", EXIT_FAILURE);
	ret[0] += hex_to_int(str[1]) << 4;
	ret[0] += hex_to_int(str[2]);
	ret[1] += hex_to_int(str[3]) << 4;
	ret[1] += hex_to_int(str[4]);
	ret[2] += hex_to_int(str[5]) << 4;
	ret[2] += hex_to_int(str[6]);
	return (ret);
}

t_vect3	parse_vect_rgb(char *str)
{
	char	**tmp;
	int		ret;
	t_vect3	rgb;
	int		i;

	if (*str == '#')
		return (parse_hex_rgb(str));
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
