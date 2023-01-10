/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:30 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 12:00:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

/*
Assign x y z to t_vect3 struct
*/
t_vect3	vect3(double x, double y, double z)
{
	t_vect3	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
