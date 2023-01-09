#include "vect3_math.h"
#include <stdio.h>

#define WIDTH 32
#define HEIGHT 32
double	quadr_form(const double a, const double b, const double c);
double	sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r);

int main(void)
{
	// double	t = quadr_form(3, 5, -7);
	// printf("%f\n", t);
	t_vect3 camera = vect3(WIDTH/2, HEIGHT/2, 0);
	t_vect3 ray;
	double t;
	double r = 59;
	t_vect3	center = vect3(150, 150, 950);
	for (int i = HEIGHT; i >= 0 ; i--)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			ray = vect3(j, i, 100);
			t = sphere_collision(camera, ray, center, r);
			if (t > 0)
				printf("%d", (int)t);
			else
				printf(".");
				// printf(" % d", (int)t);
		}
		printf("\n");
	}
	return (0);
}