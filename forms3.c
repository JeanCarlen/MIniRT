/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:52:44 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/15 09:56:40 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

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
	char	**ret;
	char	**vector;

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
	char	**ret;
	char	**vector;

	ret = second_split(str);
	new_l->type = *ret[0];
	vector = split_string(ret[1], ',');
	put_coord_light(vector, new_l, data);
	new_l->ratio = ft_strtof(ret[2]);
	vector = split_string(ret[3], ',');
	put_color_light(vector, new_l, data);
	free_tab(ret);
}
