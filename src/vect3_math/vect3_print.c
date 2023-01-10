/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:24 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 12:00:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include <stdio.h>

/*
Print out t_vect3
*/
void	vect3_print(t_vect3 vect)
{
	printf("v3(%f, %f, %f)\n", vect.x, vect.y, vect.z);
}
