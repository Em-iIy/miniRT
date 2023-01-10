/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_formula.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:01:37 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 12:01:52 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	quadr_form(const double a, const double b, const double c)
{
	const double	discr = b * b - 4 * a * c;
	double			t1;
	double			t2;

	if (discr < 0)
		return (discr);
	else if (discr == 0)
		return ((-1 * b) / (2 * a));
	t1 = ((-1 * b) - sqrt(discr)) / (2 * a);
	t2 = ((-1 * b) + sqrt(discr)) / (2 * a);
	return (fmin(fabs(t1), fabs(t2)));
}
