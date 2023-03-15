/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:54:41 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/15 09:55:21 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	put_color_form(char **vector, t_form *new_f, t_data *data)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	new_f->color.x = ft_strtof(vector[0]);
	new_f->color.y = ft_strtof(vector[1]);
	new_f->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void	put_orient_form(char **vector, t_form *new_f, t_data *data)
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

void	put_coord_form(char **vector, t_form *new_f, t_data *data)
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

void	put_color_light(char **vector, t_light *new_l, t_data *data)
{
	if (tab_check_rgb(vector) < 0)
	{
		if (vector)
			free_tab(vector);
		close_window(data);
	}
	new_l->color.x = ft_strtof(vector[0]);
	new_l->color.y = ft_strtof(vector[1]);
	new_l->color.z = ft_strtof(vector[2]);
	free_tab(vector);
}

void	put_coord_light(char **vector, t_light *new_l, t_data *data)
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
