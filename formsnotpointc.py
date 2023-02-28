
								/*SPHERE*/
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
	ret = second_split(tab[x]);
	print_tab(ret);
	new_f->type = 'S';
	vector = split_string(ret[1], ',');
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
	new_f->sphere_rad = (ft_strtof(ret[2]) / 2);
	vector = split_string(ret[3], ',');
	if (tab_check_rgb(vector) < 0)
	{
		if (ret)
			free_tab(ret);
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	new_f->color.x = ft_strtof(vector[0]);
	new_f->color.y = ft_strtof(vector[1]);
	new_f->color.z = ft_strtof(vector[2]);
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
	free_tab(vector);
	free_tab(ret);	
}

								PLAN
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
	ret = second_split(tab[x]);
	print_tab(ret);
	new_f->type = 'P';
	vector = split_string(ret[1], ',');
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
	vector = split_string(ret[2], ',');
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
	vector = split_string(ret[3], ',');
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
	if (data->object == NULL)
		data->object = new_f;
	else
	{
		last = last_obj(data);
		last->next = new_f;
	}
	free_tab(vector);
	free_tab(ret);
}



								CYLINDRE
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
	cylindre_2(str, new_f);
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
	ret = second_split(tab[x]);
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
*/