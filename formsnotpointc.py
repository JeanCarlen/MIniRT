
	##################################SPHERE##################################
/*
void	sphere(char *str)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	new_f->id = (x+1);
	if (does_it_segf(tab[x]) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	sphere_2(tab[x], new_f);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
	free_tab(ret);	
}

void	sphere_2(char *str, t_form *new_f)
{
	char **ret;

	ret = second_split(str);
	new_f->type = 'S';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f);
	new_f->sphere_rad = (ft_strtof(ret[2]) / 2);
	vector = split_string(ret[3], ',');
	put_color_form(vector, new_f);
}

			##################################PLAN##################################
/*
void	plan(char *str)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	new_f->id = (x+1);
	if (does_it_segf(tab[x]) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	plan_2(tab[x], new_f);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
	free_tab(ret);
}

void plan_2(char *str, t_form *new_f)
{
	char **ret;

	ret = second_split(str);
	new_f->type = 'P';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f);
	vector = split_string(ret[2], ',');
	put_orient_form(vector, new_f);
	vector = split_string(ret[3], ',');
	put_color_form(vector, new_f);
}




##################################CYLINDRE##################################
/*
void cylindre(char *str)
{
	t_form	*new_f;
	t_form	*last;
	new_f = init_form();
	
	if (does_it_segf(tab[x]) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	cylindre_2(tab[x], new_f);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
}

void cylindre_2(char *str, t_form *new_f)
{
	char **ret;

	ret = second_split(str);
	new_f->type = 'C';
	vector = split_string(ret[1], ',');
	put_coord_form(vector, new_f);
	vector = split_string(ret[2], ',');
	put_orient_form(vector, new_f);
	new_f->cyl_dia = ft_strtof(ret[3]);
	new_f->cyl_height = ft_strtof(ret[4]);
	vector = split_string(ret[5], ',');
	put_color_form(vector, new_f);
	free_tab(ret);
}

##################################Put_cam##################################

void	cam(char *str)
{
	if (does_it_segf(tab[x]) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	ret = second_split(tab[x]);
	vector = split_string(ret[1], ',');
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}				
	data->camera.pos.x = ft_strtof(vector[0]);
	data->camera.pos.y = ft_strtof(vector[1]);
	data->camera.pos.z = ft_strtof(vector[2]);
	free_tab(vector);
	vector = split_string(ret[2], ',');
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	data->camera.orient.x = ft_strtof(vector[0]);
	data->camera.orient.y = ft_strtof(vector[0]);
	data->camera.orient.z = ft_strtof(vector[0]);
	data->camera.fov = ft_stoi(ret[3]);
	free_tab(vector);
	free_tab(ret);
}

##################################Put_AMB##################################

void	ambiant(char *str)
{
	t_light	*new_l;
	t_light	*last;
	new_l = init_light();

	if (does_it_segf(tab[x]) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	ret = second_split(tab[x]);
	new_l->type = *ret[0];
	new_l->ratio = ft_strtof(ret[1]);
	vector = split_string(ret[2], ',');
	put_color_light(vector, new_l);
	if (data->light == NULL)
		data->light = new_l;
	else
	{
		last = last_light(data);
		last->next = new_l;
	}
	free_tab(vector);
	free_tab(ret);
}

##################################Put_form##################################

void put_color_form(char **tab, t_form *new_f)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);;
	}
	new_f->color.x = ft_strtof(vector[0]);
	new_f->color.y = ft_strtof(vector[1]);
	new_f->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_orient_form(char **tab, t_form *new_f)
{
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_f->orient.x = ft_strtof(vector[0]);
	new_f->orient.y = ft_strtof(vector[1]);
	new_f->orient.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_coord_form(char **tab, t_form *new_f)
{
	new_f->id = (x+1);
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_f->coord.x = ft_strtof(vector[0]);
	new_f->coord.y = ft_strtof(vector[1]);
	new_f->coord.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_color_light(char **tab, t_light *new_l)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);;
	}
	new_l->color.x = ft_strtof(vector[0]);
	new_l->color.y = ft_strtof(vector[1]);
	new_l->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_orient_light(char **tab, t_light *new_l)
{
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_l->orient.x = ft_strtof(vector[0]);
	new_l->orient.y = ft_strtof(vector[1]);
	new_l->orient.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void put_coord_light(char **tab, t_light *new_l)
{
	new_l->id = (x+1);
	if (tab_check(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}	
	new_l->coord.x = ft_strtof(vector[0]);
	new_l->coord.y = ft_strtof(vector[1]);
	new_l->coord.z = ft_strtof(vector[2]);
	free_tab(vector);
}
*/