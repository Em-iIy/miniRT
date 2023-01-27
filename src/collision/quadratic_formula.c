/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quadratic_formula.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:01:37 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/27 14:05:07 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "objects.h"

t_intersect	quadr_form(const double a, const double b, const double c)
{
	const double	discr = b * b - 4 * a * c;
	double			t1;
	double			t2;
	t_intersect		ret;

	if (discr < 0)
		return (create_return(discr, discr));
	else if (discr == 0)
		return (create_return((-1 * b) / (2 * a), (-1 * b) / (2 * a)));
	t1 = ((-1 * b) - sqrt(discr)) / (2 * a);
	t2 = ((-1 * b) + sqrt(discr)) / (2 * a);
	return (create_return(t1, t2));
}
