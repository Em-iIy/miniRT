/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vect3_abs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 11:32:05 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/27 14:26:15 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include <math.h>

double	vect3_abs(t_vect3 v)
{
	return (sqrt(vect3_dot(v, v)));
}
