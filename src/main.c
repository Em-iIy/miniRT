/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:23:36 by gwinnink          #+#    #+#             */
/*   Updated: 2023/01/11 12:35:15 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect3_math.h"
#include "collision.h"
#include "objects.h"
#include "MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTH 1000
#define HEIGHT 1000
#define DIST 1
#define FOV 90

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	main(void)
{
	mlx_t			*mlx;
	const t_vect3	camera = vect3(WIDTH / 2, HEIGHT / 2, 0);
	const double	step = DIST * tan(FOV / 2) / WIDTH / 2;
	t_object		*objs;
	t_vect3			ray;
	double 			t;
	int				color;
	mlx_image_t		*img;

	mlx = mlx_init(WIDTH, HEIGHT, "minirt", false);
	img = mlx_new_image(mlx, WIDTH + 1, HEIGHT + 1);
	objs = NULL;
	obj_add_front(&objs, obj_sp(obj_new(vect3(501, 500, 20), get_rgba(255, 0, 0, 255)), 3));
	obj_add_front(&objs, obj_sp(obj_new(vect3(500, 501, 21), get_rgba(0, 255, 0, 255)), 3));
	obj_add_front(&objs, obj_sp(obj_new(vect3(499, 510, 19), get_rgba(0, 0, 255, 255)), 3));
	obj_add_front(&objs, obj_pl(obj_new(vect3(0, 1000, 0), get_rgba(120, 100, 100, 255)), vect3(0, 1, 0)));
	vect3_print(camera);
	printf("step size = %f\n", step);
	for (double i = 0; i < HEIGHT ; i++)
	{
		for (double j = 0; j < WIDTH; j++)
		{
			ray = vect3((j - WIDTH / 2) * step, (i - HEIGHT / 2) * step, DIST);
			t = -1;
			color = get_collision(camera, ray, objs, &t);
			if (t > 0)
				mlx_put_pixel(img, j, i, color);
			else
				mlx_put_pixel(img, j, i, 0x0);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
