#include "MiniRT.h"

t_vector	ft_mult_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}

t_vector	add_values(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
