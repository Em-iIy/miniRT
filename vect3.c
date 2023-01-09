#include "vect3_math.h"

/*
Assign x y z to t_vect3 struct
*/
t_vect3	vect3(double x, double y, double z)
{
	t_vect3 ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
