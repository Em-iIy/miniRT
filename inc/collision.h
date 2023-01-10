/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:03:00 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 12:03:45 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "vect3_math.h"

double	quadr_form(const double a, const double b, const double c);
double	sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r);

#endif