/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:23:36 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/12 15:25:34 by gwinnink         ###   ########.fr       */
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
#define FOV 150
#define DIST 1

t_vect3	cast_ray(t_scene scene, const double dist, double x, double y)
{
	const t_vect3	right = vect3_normalize(scene.camera.pos, vect3_add(scene.camera.pos, vect3(WIDTH / 2, 0, 0)));
	const t_vect3	up = vect3_normalize(scene.camera.pos, vect3_add(scene.camera.pos, vect3(0, HEIGHT / 2, 0)));
	t_vect3			p1;
	t_vect3			p2;
	// t_vect3			p3;
	t_vect3			ret;

	p1 = vect3_substract(vect3_add(scene.camera.pos, vect3_multiply(scene.camera.orient, dist)), vect3_multiply(right, WIDTH / 2));
	// p3 = vect3_add(vect3_add(scene.camera.pos, vect3_multiply(scene.camera.orient, dist)), vect3_multiply(right, WIDTH / 2));
	p2 = vect3_add(p1, vect3_multiply(right, x));
	ret = vect3_add(p2, vect3_multiply(up, y));
	// vect3_print(p1);
	// vect3_print(p2);
	// vect3_print(p3);
	// vect3_print(ret);
	// printf("\n");
	return (ret);
}

int	main(void)
{
	mlx_t			*mlx;
	t_scene			scene;
	const double	dist = (WIDTH / 2) / tan(((FOV / 2) * (M_PI / 180)) * (M_PI / 180));
	const double	step = DIST * tan((FOV / 2) * (M_PI / 180)) / WIDTH / 2;
	t_vect3			ray;
	double 			t;
	int				color;
	mlx_image_t		*img;

	mlx = mlx_init(WIDTH, HEIGHT, "MiniReTweet", false);
	img = mlx_new_image(mlx, WIDTH + 1, HEIGHT + 1);
	init_scene(NULL, &scene);
	printf("step = %f\n",dist);
	for (double y = 0; y < HEIGHT ; y++)
	{
		for (double x = 0; x < WIDTH; x++)
		{
			// ray = vect3_add(vect3((x - WIDTH / 2), (y - HEIGHT / 2), dist), scene.camera.pos);
			ray = vect3((x - WIDTH / 2) * step, (y - HEIGHT / 2) * step, DIST);
			// vect3_print(ray);
			// ray = cast_ray(scene, dist, x, y - HEIGHT / 2);
			// vect3_print(ray);
			t = -1;
			color = get_collision((void *)&scene, ray, &t);
			mlx_put_pixel(img, x, HEIGHT - y, color);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
