/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:23:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/14 15:57:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_scene			scene;
	t_vect3			ray;
	int				color;
	mlx_image_t		*img;

	if (argc != 2)
		error_msg_exit("Invalid arguments!\n", EXIT_FAILURE);
	scene.mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", true);
	img = mlx_new_image(scene.mlx, WIDTH + 1, HEIGHT + 1);
	init_scene(argv[1], &scene);
	for (double y = 0; y < HEIGHT ; y++)
	{
		for (double x = 0; x < WIDTH; x++)
		{
			ray = cast_ray(scene, x, HEIGHT / 2 - y);
			color = get_collision((void *)&scene, ray);
			mlx_put_pixel(img, x, y, color);
		}
	}
	mlx_image_to_window(scene.mlx, img, 0, 0);
	mlx_loop(scene.mlx);
}
