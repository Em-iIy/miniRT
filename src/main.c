/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:23:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/02/15 15:03:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include <stdlib.h>

static void	detect_key(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit (0);
}

static void	paint_pixels_loop(t_scene *scene, mlx_image_t *img)
{
	t_vect3	ray;
	int		colour;
	double	x;
	double	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = cast_ray(*scene, x, HEIGHT / 2 - y);
			colour = get_collision((void *)scene, ray);
			mlx_put_pixel(img, x, y, colour);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_scene			scene;
	mlx_image_t		*img;

	if (argc != 2)
		error_msg_exit("Invalid arguments!\n", EXIT_FAILURE);
	scene.mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", true);
	img = mlx_new_image(scene.mlx, WIDTH + 1, HEIGHT + 1);
	init_scene(argv[1], &scene);
	paint_pixels_loop(&scene, img);
	mlx_image_to_window(scene.mlx, img, 0, 0);
	mlx_key_hook(scene.mlx, &detect_key, NULL);
	mlx_loop(scene.mlx);
}
