/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:52:44 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/20 14:01:13 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow(int a, int exponent)
{
	int	i;

	i = 0;
	while (i < exponent)
	{
		a *= a;
		i++;
	}
	return (a);
}

double	ft_atod(const char *str)
{
	const char	*temp = ft_strchr(str, '.');
	double		ret;

	ret = ft_atoi(str);
	ret += ft_atoi(temp + 1) / pow(10, ft_strlen(temp + 1));
	return (ret);
}