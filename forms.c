/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:50:19 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/15 09:54:17 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	sphere(char *str, int x, t_data *data)
{
	t_form	*new_f;
	t_form	*last;

	new_f = init_form();
	new_f->id = (x + 1);
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
	char	**ret;
	char	**vector;

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
	new_f->id = (x + 1);
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

void	plan_2(char *str, t_form *new_f, t_data *data)
{
	char	**ret;
	char	**vector;

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

void	put_coord_cam(char **vector, t_data *data)
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
