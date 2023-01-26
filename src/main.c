/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:23:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/26 15:11:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "objects.h"
#include "MLX42/MLX42.h"
#include "scene.h"
#include "libft.h"
#include "parse.h"
#include "error.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

t_vect3	cast_ray(t_scene scene, double x, double y);

void	func(mouse_key_t button, action_t action, modifier_key_t mods, void *void_scene)
{
	t_scene	*scene;
	int32_t	x, y;
	t_vect3	ray;

	scene = (t_scene *)void_scene;
	mlx_get_mouse_pos(scene->mlx, &x, &y);
	printf("click (%d, %d)\n", x, y);
	ray = cast_ray(*scene, x, HEIGHT / 2 - y);
	get_collision(void_scene, ray);
}

int	main(int argc, char **argv)
{
	t_scene			scene;
	t_vect3			ray;
	int				color;
	mlx_image_t		*img;

	if (argc != 2)
		error_msg_exit("Invalid arguments!\n", EXIT_FAILURE);
	scene.mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", false);
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
	mlx_mouse_hook(scene.mlx, &func, (void *)&scene);
	mlx_image_to_window(scene.mlx, img, 0, 0);
	mlx_loop(scene.mlx);
}
