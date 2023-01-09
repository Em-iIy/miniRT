#include "vect3_math.h"

t_vect3	vect3_add(t_vect3 a, t_vect3 b)
{
	t_vect3	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}
