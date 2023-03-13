/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:48 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/14 00:25:10 by jeancarlen       ###   ########.fr       */
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
	// t_vector	zawaldo;
	t_vector	temp1;
	t_vector	temp2;
	t_vector	new_x;
	t_vector	new_y;
	t_vector	new_z;
	
	data->rays.ray_orig.x = data->camera.pos.x;
	data->rays.ray_orig.y = data->camera.pos.y;
	data->rays.ray_orig.z = data->camera.pos.z;
	data->rays.ray_dir.x = ((float)data->mlx.win_y - W / 2);
	data->rays.ray_dir.y = ((float)data->mlx.win_i - H / 2);
	data->rays.ray_dir.z = W / (2 * tan(data->camera.fov / 2));
	new_x = ft_mult(data->rays.ray_dir.x, data->camera.right);
	new_y = ft_mult(data->rays.ray_dir.y, data->camera.up);
	new_z = ft_mult(data->rays.ray_dir.z, data->camera.orient);
	temp1 = ft_plus(new_x, new_y);
	temp2 = ft_plus(temp1, new_z);
	data->rays.ray_dir = normalize(temp2);
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