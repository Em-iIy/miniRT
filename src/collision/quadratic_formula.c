/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_formula.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:01:37 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 18:25:45 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "objects.h"

double	quadr_form(const double a, const double b, const double c)
{
	const double	discr = b * b - 4 * a * c;
	double			t1;
	double			t2;

	if (discr < 0 || a == 0)
		return (0);
	else if (discr == 0)
		return (fmin_pos((-1 * b) / (2 * a), (-1 * b) / (2 * a)));
	t1 = ((-1 * b) - sqrt(discr)) / (2 * a);
	t2 = ((-1 * b) + sqrt(discr)) / (2 * a);
	return (fmin_pos(t1, t2));
}
