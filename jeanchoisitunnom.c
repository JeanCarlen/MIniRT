#include "MiniRT.h"

t_light	*get_light_type(t_light *light, char type)
{
	while (light && light->type != type)
		light = light->next;
	return (light);
}