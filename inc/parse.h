/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:34:12 by gwinnink          #+#    #+#             */
/*   Updated: 2023/02/07 15:33:38 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "scene.h"

void		parse_camera(t_camera *cam, char **line);
void		parse_light(t_light *light, char **line);
void		parse_amblight(t_amblight *light, char **line);
void		parse_sphere(t_object **objs, char **line);
void		parse_plane(t_object **objs, char **line);
void		parse_cyl(t_object **objs, char **line);

int			parse_rgb(char *str);
t_vect3		parse_vect_rgb(char *str);
t_vect3		parse_coords(char *str);
t_vect3		parse_direction(char *str);
double		ft_atod(char *str);

int			parse_file_name(char *infile);
void		parse_line(t_scene *scene, char *line);

#endif