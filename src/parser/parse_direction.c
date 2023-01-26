/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:01:10 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/26 14:59:40 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "error.h"
#include "vect3_math.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_valid(double d)
{
	return (d >= -1 && d <= 1);
}

t_vect3	parse_direction(char *str)
{
	const t_vect3	ret = parse_coords(str);

	if (!is_valid(ret[0]) || !is_valid(ret[1]) || !is_valid(ret[2]))
		error_msg_exit("Parse error: invalid vector\n", EXIT_FAILURE);
	return (vect3_normalize(vect3_0(), ret));
}
