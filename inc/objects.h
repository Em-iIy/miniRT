/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:37:49 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/16 19:20:22 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vect3_math.h"

enum e_obj
{
	SPHERE,
	CYLINDER,
	PLANE,
	CIRCLE
};

typedef struct s_object
{
	struct s_object	*next;
	int				type;
	t_vect3			color;
	t_vect3			pos;
	t_vect3			orient;
	double			diameter;
	double			lenght;
	double			radius;
	int				inside;
}	t_object;

typedef struct s_scene	t_scene;

double		fmin_pos(const double d1, const double d2);
double		quadr_form(const double a, const double b, const double c);
int			get_collision(t_scene *scene, t_vect3 ray);
double		sphere_coli(t_vect3 o, t_vect3 d, t_vect3 c, double r);
double		circle_coli(t_vect3 ray, t_vect3 pos, t_object *c);
double		plane_coli(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n);
double		cylinder_coli(t_vect3 ray, t_vect3 pos, t_object *cyl);

t_object	*obj_sp(t_object *obj, double diameter);
t_object	*obj_pl(t_object *obj, t_vect3 orientation);
void		obj_cy(t_object **objs, t_vect3 orientation, \
	double length, double diameter);

t_object	*obj_new(t_vect3 coords, t_vect3 color);
void		obj_add_front(t_object **head, t_object *new);
void		obj_free_all(t_object **head);

#endif