#include "vect3_math.h"

/*
Multiply t_vect3 with scalar
*/
t_vect3	vect3_multiply(t_vect3 vect, double s)
{
	t_vect3	ret;

	ret.x = vect.x * s;
	ret.y = vect.y * s;
	ret.z = vect.z * s;
	return (ret);
}