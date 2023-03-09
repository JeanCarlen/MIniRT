/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:48 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/08 15:33:35 by fmalizia         ###   ########.ch       */
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
	t_vector	zawaldo;
	float		ratio;
	float		v_range;
	
	ratio = (float)IMG_WIDTH / (float)IMG_HEIGHT;
	v_range  = tan(data->camera.fov * 0.5);
	data->rays.ray_orig.x = data->camera.pos.x;
	data->rays.ray_orig.y = data->camera.pos.y;
	data->rays.ray_orig.z = data->camera.pos.z;
	zawaldo.x = (2 * ((data->mlx.win_y + 0.5) / IMG_WIDTH) - 1)
		* v_range * ratio;
	zawaldo.y = (1 - 2 * ((data->mlx.win_i + 0.5) / IMG_HEIGHT))
		* v_range;
	zawaldo.z = 1;
	data->rays->ray_dir =
	// data->rays.ray_dir.x = ((float)data->mlx.win_y - W / 2);
	// data->rays.ray_dir.y = ((float)data->mlx.win_i - H / 2);
	// data->rays.ray_dir.z = -W / (2 * tan(data->camera.fov / 2));
	// printf("%f %f %f\n", data->rays.ray_dir.x,data->rays.ray_dir.y,data->rays.ray_dir.z);
}

/*
t_bool	camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v)
{
	t_vec3		worldspace;

	worldspace.x = (2 * ((u + 0.5) / scene->mlx.width) - 1)
		* scene->camera->view_range * scene->ratio;
	worldspace.y = (1 - 2 * ((v + 0.5) / scene->mlx.height))
		* scene->camera->view_range;
	worldspace.z = 1;
	ray->origin = mat4_get(scene->camera->world, m_origin);
	ray->dir = vec3_unit(mat4_mult_dir(scene->camera->world,
				worldspace));
	ray->max = M_INFINITY;
	return (true);
}
*/