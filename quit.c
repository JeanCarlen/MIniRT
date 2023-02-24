/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:35:23 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 16:08:47 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	escape(int keycode, t_data *data)
{
	if (keycode == DOWN)
		data->camera.pos.y += 0.5;
	if (keycode == UP)
		data->camera.pos.y -= 0.5;
	if (keycode == RIGHT)
		data->camera.pos.x += 10;
	if (keycode == LEFT)
		data->camera.pos.x -= 10;
	if (keycode == J_KEY)
		data->camera.pos.z += 1;
	if (keycode == K_KEY)
		data->camera.pos.z -= 1;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, W, H);
	load_scene(data);
	return (0);
}
