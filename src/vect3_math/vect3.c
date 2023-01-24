/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:30 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/24 18:10:34 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

/*
Assign x y z to t_vect3
*/
t_vect3	vect3(double x, double y, double z)
{
	return ((t_vect3){x, y, z});
}

/*
Initializes t_vect3 as (0, 0, 0)
*/
t_vect3	vect3_0(void)
{
	return ((t_vect3){0, 0, 0});
}
