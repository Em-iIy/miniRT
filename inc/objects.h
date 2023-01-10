/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:37:49 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/10 17:59:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vect3_math.h"

enum e_obj
{
	SPHERE,
	CYLINDER,
	PLANE
};

typedef struct s_object
{
	struct s_object	*next;
	int				type;
	int				color;
	t_vect3			coords;
	t_vect3			orientation;
	double			diameter;
	double			lenght;
	double			radius;
}	t_object;

int			get_collision(t_vect3 o, t_vect3 d, t_object *objs, double *t);
double		sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r);
double	plane_collision(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n);

t_object	*obj_sp(t_object *obj, double radius);
t_object	*obj_pl(t_object *obj, t_vect3 orientation);
t_object	*obj_cy(t_object *obj, t_vect3 orientation, \
	double length, double diameter);

t_object	*obj_new(t_vect3 coords, int color);
void		obj_add_front(t_object **head, t_object *new);
void		obj_free_all(t_object **head);

#endif