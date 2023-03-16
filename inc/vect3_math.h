/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:03:57 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 18:35:18 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT3_MATH_H
# define VECT3_MATH_H

typedef double	t_vect3 __attribute__ ((vector_size(32)));

t_vect3	vect3(double x, double y, double z);
t_vect3	vect3_0(void);
double	vect3_abs(t_vect3 v);
double	vect3_dot(t_vect3 a, t_vect3 b);
t_vect3	vect3_cross_product(t_vect3 a, t_vect3 b);
t_vect3	vect3_normalize(t_vect3 origin, t_vect3 vect);
void	vect3_print(const char *name, t_vect3 vect);

#endif
