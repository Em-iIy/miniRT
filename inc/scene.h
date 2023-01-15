/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:23:16 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/01/12 18:37:18 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "objects.h"
# include "vect3_math.h"
# include "MLX42/MLX42.h"

typedef struct s_amblight
{
	float	brightness;
	int		colour;
}	t_amblight;

typedef struct s_camera
{
	t_vect3	pos;
	t_vect3	orient;
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
