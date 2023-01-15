/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quadratic_formula.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:01:37 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/13 18:18:39 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "vect3_math.h"

static t_double_intersect	create_return(double close, double far)
{
	t_double_intersect	ret;

	ret.close = close;
	ret.far = far;
	return (ret);
}

t_double_intersect	quadr_form(const double a, const double b, const double c)
{
	const double		discr = b * b - 4 * a * c;
	double				t1;
	double				t2;
	t_double_intersect	ret;
	

	if (discr < 0)
		return (create_return(discr, discr));
	else if (discr == 0)
		return (create_return((-1 * b) / (2 * a), (-1 * b) / (2 * a)));
	t1 = ((-1 * b) - sqrt(discr)) / (2 * a);
	t2 = ((-1 * b) + sqrt(discr)) / (2 * a);

	if (t1 > 0 && (t1 < t2 || t2 < 0))
		return (create_return(t1, t2));
	else if (t2 > 0 && (t2 < t1 || t1 < 0))
		return (create_return(t2, t1));
	return (create_return(0, 0));
}
