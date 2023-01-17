/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:23:16 by fpurdom           #+#    #+#             */
/*   Updated: 2023/01/17 13:57:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "objects.h"
# include "vect3_math.h"
# include "MLX42/MLX42.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_amblight
{
	float	brightness;
	int		colour;
}	t_amblight;

typedef struct s_camera
{
	t_vect3	pos;
	t_vect3	orient;
	t_vect3	right;
	t_vect3	up;
	double	dist;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_vect3	pos;
	float	brightness;
	int		colour;
}	t_light;

typedef struct s_scene
{
	mlx_t		*mlx;
	t_amblight	amlight;
	t_camera	camera;
	t_light		light;
	t_object	*objs;
}	t_scene;

void	init_scene(char	*infile, t_scene *scene);

#endif
