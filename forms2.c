/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:51:25 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/15 10:11:10 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	cylindre(char *str, int x, t_data *data)
{
	t_form	*new_f;
	t_form	*last;

	new_f = init_form();
	new_f->id = (x + 1);
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

void	cylindre_2(char *str, t_form *new_f, t_data *data)
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
	char	**ret;
	char	**vector;

	ret = NULL;
	vector = NULL;
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
	cam2(data);
	free_tab(ret);
}

void	cam2(t_data *data)
{
	data->camera.up = normalize(add_values(0, 1, 0));
	data->camera.right = cross(data->camera.orient, data->camera.up);
	if (getnorm(data->camera.right) == 0.0f)
	{
		data->camera.up = normalize(add_values(0, 0, 1));
		data->camera.right = cross(data->camera.orient, data->camera.up);
	}
	data->camera.right = normalize(data->camera.right);
	data->camera.up = normalize(cross(data->camera.orient, data->camera.right));
}

void	put_orient_cam(char **vector, t_data *data)
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
