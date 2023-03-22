/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:24 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/22 11:51:29 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	gnl_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

void	*gnl_calloc(unsigned int count, size_t size)
{
	char			*ret_ptr;
	unsigned int	i;

	i = 0;
	ret_ptr = (char *)malloc(count * size);
	if (!ret_ptr)
		exit(EXIT_FAILURE);
	while (i < count * size)
	{
		ret_ptr[i] = 0;
		i++;
	}
	return ((void *)ret_ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)gnl_calloc(1, 1);
	ret_str = (char *)gnl_calloc(gnl_strlen(s1) + gnl_strlen(s2) + 1, 1);
	if (!ret_str)
		return (NULL);
	while (s1[i])
	{
		ret_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		ret_str[i + j] = s2[j];
		j++;
	}
	return (ret_str);
}

char	*gnl_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}
