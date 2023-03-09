/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:42 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/08 11:55:20 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static int	setup_data(char *arg, t_data *data)
{
	char	**tab;
	char	*lines;

	tab = NULL;
	init_all(data);
	lines = readfile(arg);
	tab = split_string(lines, '\n');
	convert_tab(tab, data);
	if (lines)
		free(lines);
	return (0);
}

int	check_args(char *arg)
{
	if (!strchr(arg, '.'))
	{
		printf("%s\n", "Invalid file!");
		exit(1);
	}
	if (ft_strncmp((ft_strrchr(arg, '.')), ".rt", 4))
	{
		printf("%s\n", "Invalid extension!");
		exit(1);
	}
	return (0);
}

void	run_program(t_data *data)
{
	data->camera.fov = data->camera.fov * (M_PI / 180);
	ft_init_window(data);
	load_scene(data);
	mlx_key_hook(data->mlx.win_ptr, escape, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->test  = 0;
	if (argc == 2)
	{
		check_args(argv[1]);
		if (setup_data(argv[1], data) < 0)
		{
			printf("Error in the line");
			return (-1);
		}
		run_program(data);
	}
	else
	{
		printf("You have the launch the program with an .rt file\n");
		return (0);
	}
	return (0);
}
