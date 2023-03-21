/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmin_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:06:03 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/21 16:17:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	fmin_pos(const double d1, const double d2)
{
	if (d1 > 0.00001 && (d2 < 0.00001 || d1 < d2))
		return (d1);
	if (d2 > 0.00001 && (d1 < 0.00001 || d2 < d1))
		return (d2);
	return (0);
}
