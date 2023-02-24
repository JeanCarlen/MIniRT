/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:42 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 11:06:59 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

/*/
void	check_args(char *arg)
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
}

int	read_doc(t_rays *rays, char *arg)
{
	char	*line;	
	char	*comb;
	int		fd;

	fd = open(arg, O_RDONLY);
	comb = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		comb = ft_strjoin(comb, line);
		free(line);
	}
	rays->map = ft_split(comb, '\n');
	close(fd);
	return (0);
}
*/

static int setup_data(char *arg)
{
	t_data *data;
	char **tab;
	char *lines;

	tab = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
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

	if (argc == 2)
	{
		//rays = init_struct();
		if (setup_data(argv[1]) < 0)
		{
			printf("Error in the line");
			return (-1);
		}
		/*check_args(argv[1]);
		read_doc(rays, argv[1]);
		get_info(rays);
		load_scene(rays);
		mlx_key_hook(rays->win_ptr, escape, rays);
		mlx_hook(rays->win_ptr, 17, 0, close_window, rays);
		mlx_loop(rays->mlx_ptr);
		mlx_destroy_window(rays->mlx_ptr, rays->win_ptr);*/
	}
	else
	{
		printf("You have the launch the program with an .rt file\n");
		return (0);
	}
	return (0);
}
