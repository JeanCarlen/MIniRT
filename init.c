/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:48 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/02 11:20:26 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	ft_init_window(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, W, H, "MiniRT");
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, W, H);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
}

void	set_scene(t_data *data)
{
	data->rays.ray_orig.x = data->camera.pos.x;
	data->rays.ray_orig.y = data->camera.pos.y;
	data->rays.ray_orig.z = data->camera.pos.z;
	data->rays.ray_dir.x = ((float)data->mlx.win_y - W / 2);
	data->rays.ray_dir.y = ((float)data->mlx.win_i - H / 2);
	data->rays.ray_dir.z = -W / (2 * tan(data->camera.fov / 2));
}
