/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:23:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2023/01/20 18:59:36 by fpurdom       ########   odam.nl         */
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

// #define FOV 170
// #define DIST 1

t_vect3					cast_ray(t_scene scene, double x, double y);

mlx_mousefunc	func(mouse_key_t button, action_t action, modifier_key_t mods, void *void_scene)
{
	t_scene	*scene;
	int32_t	x, y;
	t_vect3	ray;
	// const double	step = DIST * tan((FOV / 2) * (M_PI / 180)) / WIDTH / 2;
	// const double	dist = (WIDTH / 2) / tan(((FOV / 2) * (M_PI / 180)) * (M_PI / 180));

	scene = (t_scene *)void_scene;
	mlx_get_mouse_pos(scene->mlx, &x, &y);
	printf("click (%d, %d)\n", x, y);
	// ray = vect3((x - WIDTH / 2) * step, (y - HEIGHT / 2) * step, DIST);
	// vect3_print(vect3_normalize(vect3(0, 0, 0), ray));
	ray = cast_ray(*scene, x, y - HEIGHT / 2);
	//vect3_print(ray);
	get_collision(void_scene, ray);
}

int	main(void)
{
	t_scene			scene;
	// const double	dist = (WIDTH / 2) / tan(((FOV / 2) * (M_PI / 180)) * (M_PI / 180));
	// const double	step = DIST * tan((FOV / 2) * (M_PI / 180)) / WIDTH / 2;
	t_vect3			ray;
	int				color;
	mlx_image_t		*img;

	scene.mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", false);
	img = mlx_new_image(scene.mlx, WIDTH + 1, HEIGHT + 1);
	init_scene(NULL, &scene);
	printf("step = %f\n", scene.camera.dist);
	for (double y = 0; y < HEIGHT ; y++)
	{
		for (double x = 0; x < WIDTH; x++)
		{
			// ray = vect3_add(vect3((x - WIDTH / 2), (y - HEIGHT / 2), dist), scene.camera.pos);
			// ray = vect3((x - WIDTH / 2) * step, (y - HEIGHT / 2) * step, DIST);
			ray = cast_ray(scene, x, HEIGHT / 2 - y);
			color = get_collision((void *)&scene, ray);
			mlx_put_pixel(img, x, y, color);
		}
	}
	mlx_mouse_hook(scene.mlx, &func, (void *)&scene);
	mlx_image_to_window(scene.mlx, img, 0, 0);
	mlx_loop(scene.mlx);
}
