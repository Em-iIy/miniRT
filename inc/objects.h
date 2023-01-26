/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 14:37:49 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/26 15:10:28 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vect3_math.h"
# include <stdbool.h>

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
	int				color;
	t_vect3			pos;
	t_vect3			orient;
	double			diameter;
	double			lenght;
	double			radius;
}	t_object;

t_double_intersect		create_return(double t1, double t2);
t_double_intersect		quadr_form(const double a, const double b, const double c);
int						get_collision(void *void_scene, t_vect3 ray);
t_double_intersect		sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r);
t_double_intersect		circle_collision(t_vect3 ray, t_vect3 pos, t_object *c);
t_double_intersect		plane_collision(t_vect3 r_o, t_vect3 d, t_vect3 p_o, t_vect3 n);
t_double_intersect		cyl_collision(t_vect3 ray, t_vect3 pos, t_object *cyl);

t_object	*obj_sp(t_object *obj, double diameter);
t_object	*obj_pl(t_object *obj, t_vect3 orientation);
void		obj_cy(t_object **objs, t_vect3 orientation, \
	double length, double diameter);

t_object	*obj_new(t_vect3 coords, int color);
void		obj_add_front(t_object **head, t_object *new);
void		obj_free_all(t_object **head);

#endif