#include "vect3_math.h"

double	vect3_dot_product(t_vect3 a, t_vect3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
