#include "MiniRT.h"

t_form	*init_form(void)
{
	t_form	*form;

	form = malloc (sizeof(t_form));
	if (!form)
		return (NULL);
	form->type = '\0';
	form->id = 0;
	form->coord.x = 0.0f;
	form->coord.y = 0.0f;
	form->coord.z = 0.0f;
	form->color.x = 0.0;
	form->color.y = 0.0;
	form->color.z = 0.0;
	form->orient.x = 0.0f;
	form->orient.y = 0.0f;
	form->orient.z = 0.0f;
	form->sphere_rad = 0.0f;
	form->cyl_dia = 0.0f;
	form->cyl_height = 0.0f;
	form->next = NULL;
	return (form);
}

t_light	*init_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->id = 0;
	light->color.x = 0.0;
	light->color.y = 0.0;
	light->color.z = 0.0;
	light->coord.x = 0.0f;
	light->coord.y = 0.0f;
	light->coord.z = 0.0f;
	light->ratio = 0.0f;
	light->next = NULL;
	return (light);
}

void	init_cam(t_data *data)
{
	data->camera.pos.x = 0.0f;
	data->camera.pos.y = 0.0f;
	data->camera.pos.z = 0.0f;
	data->camera.fov = 0;
	data->camera.orient.x = 0.0f;
	data->camera.orient.y = 0.0f;
	data->camera.orient.z = 0.0f;
}

void	init_all(t_data *data)
{
	data->light = NULL;
	data->object = NULL;
	init_cam(data);
}
