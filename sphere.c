#include "vect3_math.h"
#include <math.h>

double	quadr_form(const double a, const double b, const double c)
{
	const double	discr = b * b - 4 * a * c;
	double	t1;
	double	t2;

	if (discr < 0)
		return (discr);
	else if (discr == 0)
		return ((-1 * b) / (2 * a));
	t1 = ((-1 * b) - sqrt(discr))/(2 * a);
	t2 = ((-1 * b) + sqrt(discr))/(2 * a);
	// if (t1 < t2 && t1 >= 0)
	return (fmin(fabs(t1), fabs(t2)));
	// 	return (t1);
	// return (t2);
	
}

/*
(-b-+sqrt(b^2-4ac))/2a
a = d^2 = 		vect3_dot_product(d, d)
b = 2vd =		2 * vect3_dot_product(v, d)
c = v^2-r^2 = 	vect3_dot_product(v, v) - r * r
*/
double	sphere_collision(t_vect3 o, t_vect3 d, t_vect3 c, double r)
{
	const t_vect3	v = vect3_substract(o, c);

	return (quadr_form(vect3_dot_product(d, d), 2 * vect3_dot_product(v, d), vect3_dot_product(v, v) - (r * r)));
}