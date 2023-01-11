/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:23:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/11 15:46:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "objects.h"
#include "MLX42/MLX42.h"
#include "scene.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000
#define DIST 1
#define FOV 90

int	main(void)
{
	mlx_t			*mlx;
	t_scene			scene;
	const double	step = DIST * tan(FOV / 2) / WIDTH / 2;
	t_vect3			ray;
	double 			t;
	int				color;
	mlx_image_t		*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", false);
	img = mlx_new_image(mlx, WIDTH + 1, HEIGHT + 1);
	init_scene(NULL, &scene);
	for (double i = 0; i < HEIGHT ; i++)
	{
		for (double j = 0; j < WIDTH; j++)
		{
			ray = vect3((j - WIDTH / 2) * step, (i - HEIGHT / 2) * step, DIST);
			t = -1;
			color = get_collision(scene.camera.pos, ray, scene.objs, &t);
			mlx_put_pixel(img, j, HEIGHT - i, color);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
