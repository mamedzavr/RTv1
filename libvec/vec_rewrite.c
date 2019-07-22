#include "libvec.h"

void	vec_rewrite(t_vector3 *first, t_vector3 second)
{
	first->x = second.x;
	first->y = second.y;
	first->z = second.z;
}
