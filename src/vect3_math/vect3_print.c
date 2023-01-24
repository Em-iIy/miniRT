/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:24 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/24 16:14:19 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include <stdio.h>

/*
Print out t_vect3
*/
void	vect3_print(const char *name, t_vect3 v)
{
	printf("%s {%f, %f, %f}", name, v[0], v[1], v[2]);
}
