/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 13:42:55 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/14 15:31:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	error_msg_exit(char *msg, int code)
{
	write(2, msg, ft_strlen(msg));
	exit(code);
}

void	perror_msg_exit(char *msg, int code)
{
	perror(msg);
	exit(code);
}
