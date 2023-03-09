#include "MiniRT.h"

void	sphere(char *str, int x, t_data *data)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	new_f->id = (x+1);
	if (does_it_segf(str) < 0)
		close_window(data);
	sphere_2(str, new_f, data);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
}

void	sphere_2(char *str, t_form *new_f, t_data *data)
{
	char **ret = NULL;
	char **vector = NULL;

	ret = second_split(str);
	new_f->type = 'S';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f, data);
	new_f->sphere_rad = (ft_strtof(ret[2]) / 2);
	vector = split_string(ret[3], ',');
	put_color_form(vector, new_f, data);
	free_tab(ret);
}

void	plan(char *str, int x, t_data *data)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	new_f->id = (x+1);

	if (does_it_segf(str) < 0)
		close_window(data);
	plan_2(str, new_f, data);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
}

void plan_2(char *str, t_form *new_f, t_data *data)
{
	char **ret;
	char **vector;

	ret = second_split(str);
	new_f->type = 'P';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f, data);
	vector = split_string(ret[2], ',');
	put_orient_form(vector, new_f, data);
	vector = split_string(ret[3], ',');
	put_color_form(vector, new_f, data);
	free_tab(ret);
}

void cylindre(char *str, int x, t_data *data)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	
	new_f->id = (x+1);
	if (does_it_segf(str) < 0)
		close_window(data);
	cylindre_2(str, new_f, data);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
}

void cylindre_2(char *str, t_form *new_f, t_data *data)
{
	char	**ret;
	char	**vector;

	ret = second_split(str);
	new_f->type = 'C';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f, data);
	vector = split_string(ret[2], ',');
	put_orient_form(vector, new_f, data);
	new_f->cyl_dia = ft_strtof(ret[3]);
	new_f->cyl_height = ft_strtof(ret[4]);
	vector = split_string(ret[5], ',');
	put_color_form(vector, new_f, data);
	free_tab(ret);
}

void	cam(char *str, t_data *data)
{
	char	**ret = NULL;
	char	**vector = NULL;

	if (does_it_segf(str) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	ret = second_split(str);
	vector = split_string(ret[1], ',');
	put_coord_cam(vector, data);
	vector = split_string(ret[2], ',');
	put_orient_cam(vector, data);
	data->camera.fov = ft_stoi(ret[3]);
	data->camera.up = normalize(add_values(0, 1, 0));
	data->camera.right = cross(data->camera.orient, data->camera.up);
	print_vec("orient: ", data->camera.orient);
	print_vec("up: ", data->camera.up);
	print_vec("right: ", data->camera.right);
	free_tab(ret);
}

void put_orient_cam(char **vector, t_data *data)
{
	if (tab_check(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	data->camera.orient.x = ft_strtof(vector[0]);
	data->camera.orient.y = ft_strtof(vector[1]);
	data->camera.orient.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_coord_cam(char **vector, t_data *data)
{
	if (tab_check(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}				
	data->camera.pos.x = ft_strtof(vector[0]);
	data->camera.pos.y = ft_strtof(vector[1]);
	data->camera.pos.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void	ambiant(char *str, t_data *data)
{
	t_light	*new_l;
	t_light	*last;
	new_l = init_light();

	if (does_it_segf(str) < 0)
		close_window(data);
	ambiant_2(str, new_l, data);
	if (data->light == NULL)
		data->light = new_l;
	else
	{
		last = last_light(data);
		last->next = new_l;
	}
}

void	ambiant_2(char *str, t_light *new_l, t_data *data)
{
	char **ret = NULL;
	char **vector = NULL;

	ret = second_split(str);
	new_l->type = *ret[0];
	new_l->ratio = ft_strtof(ret[1]);
	vector = split_string(ret[2], ',');
	put_color_light(vector, new_l, data);
	free_tab(ret);
}

void	light(char *str, int x, t_data *data)
{
	t_light	*new_l;
	t_light	*last;
	new_l = init_light();

	new_l->id = (x + 1);

	if (does_it_segf(str) < 0)
		close_window(data);
	light_2(str, new_l, data);
	if (data->light == NULL)
		data->light = new_l;
	else
	{
		last = last_light(data);
		last->next = new_l;
	}
}

void	light_2(char *str, t_light *new_l, t_data *data)
{
	char **ret = NULL;
	char **vector = NULL;

	ret = second_split(str);
	new_l->type = *ret[0];
	vector = split_string(ret[1], ',');
	put_coord_light(vector, new_l, data);
	new_l->ratio = ft_strtof(ret[2]);
	vector = split_string(ret[3], ',');
	put_color_light(vector, new_l, data);
	free_tab(ret);
}

void put_color_form(char **vector, t_form *new_f, t_data *data)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);;
	}
	new_f->color.x = ft_strtof(vector[0]);
	new_f->color.y = ft_strtof(vector[1]);
	new_f->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_orient_form(char **vector, t_form *new_f, t_data *data)
{
	if (tab_check(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_f->orient.x = ft_strtof(vector[0]);
	new_f->orient.y = ft_strtof(vector[1]);
	new_f->orient.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_coord_form(char **vector, t_form *new_f, t_data *data)
{
	if (tab_check(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_f->coord.x = ft_strtof(vector[0]);
	new_f->coord.y = ft_strtof(vector[1]);
	new_f->coord.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_color_light(char **vector, t_light *new_l, t_data *data)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);;
	}
	new_l->color.x = ft_strtof(vector[0]);
	new_l->color.y = ft_strtof(vector[1]);
	new_l->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_coord_light(char **vector, t_light *new_l, t_data *data)
{
	if (tab_check(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_l->coord.x = ft_strtof(vector[0]);
	new_l->coord.y = ft_strtof(vector[1]);
	new_l->coord.z = ft_strtof(vector[2]);
	free_tab(vector);
}