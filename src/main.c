/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:23:36 by gwinnink          #+#    #+#             */
/*   Updated: 2023/03/22 12:12:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error.h"
#include <stdlib.h>

static void	free_scene(t_scene *scene)
{
	t_object	*temp;

	temp = scene->objs;
	while (temp)
	{
		temp = scene->objs->next;
		free(scene->objs);
		scene->objs = temp;
	}
}

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
			colour = get_collision(scene, ray);
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
	if (!scene.mlx)
		error_msg_exit("Invalid resolution!\n", EXIT_FAILURE);
	img = mlx_new_image(scene.mlx, WIDTH + 1, HEIGHT + 1);
	if (!img)
		error_msg_exit("Failed to create image\n", EXIT_FAILURE);
	init_scene(argv[1], &scene);
	paint_pixels_loop(&scene, img);
	mlx_image_to_window(scene.mlx, img, 0, 0);
	mlx_key_hook(scene.mlx, &detect_key, NULL);
	mlx_loop(scene.mlx);
	mlx_delete_image(scene.mlx, img);
	mlx_close_window(scene.mlx);
	free_scene(&scene);
	return (0);
}
