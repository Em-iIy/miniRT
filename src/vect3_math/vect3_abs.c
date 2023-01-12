/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_abs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:32:05 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/12 11:39:33 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include <math.h>

double	vect3_abs(t_vect3 vect)
{
	return (sqrt(vect3_dot_product(vect, vect)));
}
