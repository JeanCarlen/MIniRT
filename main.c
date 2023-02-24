/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:42 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 13:59:33 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"


static int setup_data(char *arg, t_data *data)
{
	char **tab;
	char *lines;

	tab = NULL;
	init_all(data);
	lines = readfile(arg);
	tab = split_string(lines, '\n');
	convert_tab(tab, data);
	/*if(tab)
		free_tab(tab);
	if(lines)
		free(lines);*/
	return 0;
}

int	main(int argc, char **argv)
{
	//t_rays	*rays;
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (argc == 2)
	{
		//rays = init_struct();
		if (setup_data(argv[1], data) < 0)
		{
			printf("Error in the line");
			return (-1);
		}
		data->camera.fov = data->camera.fov * (M_PI / 180);
		load_scene(data);
		mlx_key_hook(data->mlx.win_ptr, escape, data);
		mlx_hook(data->mlx.win_ptr, 17, 0, close_window, data);
		mlx_loop(data->mlx.mlx_ptr);
		// mlx_destroy_window(rays->mlx_ptr, rays->win_ptr);
	}
	else
	{
		printf("You have the launch the program with an .rt file\n");
		return (0);
	}
	return (0);
}
