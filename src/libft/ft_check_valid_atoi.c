/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_atoi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:14:07 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/25 16:31:48 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

static long	ft_atol(const char *str)
{
	long	ret_long;
	long	neg;
	int		i;

	ret_long = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] != '-' || str[i] != '+') && (str[i] < '0' && str[i] > '9'))
		return (0);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret_long *= 10;
		ret_long += str[i] - '0';
		i++;
	}
	return (ret_long * neg);
}


bool	ft_check_valid_atoi(int *code, char *str)
{
	long	i;

	i = 0;
	if (!str)
		return (false);
	if (ft_is_longlong(str) == false)
		return (false);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	i = ft_atol(str);
	if (i < INT_MIN || i > INT_MAX)
		return (false);
	*code = i;
	return (true);
}
