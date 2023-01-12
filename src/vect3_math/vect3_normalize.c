/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:39:59 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/12 11:45:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

/*
returns the normalized vector with a lenght of 1
(vect - origin)/absolute(vect - origin)
*/
t_vect3	vect3_normalize(t_vect3 origin, t_vect3 vect)
{
	const t_vect3	diff = vect3_substract(vect, origin);
	const double	magnitude = vect3_abs(diff);

	return (vect3_divide(diff, magnitude));
}