/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:36:55 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/12 11:37:48 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"

t_vect3	vect3_divide(t_vect3 vect, double s)
{
	return (vect3(vect.x / s, vect.y / s, vect.z / s));
}
