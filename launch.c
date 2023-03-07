/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:27 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/27 160:50 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	load_scene(t_data *data)
{
	data->mlx.win_i = 0;
	while (data->mlx.win_i < H)
	{
		data->mlx.win_y = 0;
		while (data->mlx.win_y < W)
		{
			set_scene(data);
			data->rays.hit_id = 0;
			if (routine_inter(data, &(data->rays)))
			{
				data->rays.col = get_light(data);
				// data->rays.col = add_amb(data, &data->rays);
				my_mlx_pixel_put(data, data->mlx.win_y,
					(H - data->mlx.win_i - 1), color(ft_max(data->rays.col.x),
						ft_max(data->rays.col.y), ft_max(data->rays.col.z)));
			}
			data->mlx.win_y++;
		}
		data->mlx.win_i++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img, 0, 0);
}

t_vector	add_amb(t_data *data, t_rays *ray)
{
	ray->col.x *= (data->light->color.x \
	* data->light->ratio);
	ray->col.y *= (data->light->color.y \
	* data->light->ratio);
	ray->col.z *= (data->light->color.z \
	* data->light->ratio);
	return (ray->col);
}

t_vector	get_light(t_data *data)
{
	double		dot_light;
	t_vector	minus_tmp;
	int			shadow;
	t_light		*c_light;
	t_rays		ray_light;

	shadow = FALSE;
	c_light = data->light;
	c_light = light_details(data, c_light);
	if (!c_light)
	{
		ray_light.n = data->rays.col;
		return (ray_light.n);
	}
	minus_tmp = minus(c_light->coord, data->rays.p);
	dot_light = getnorm(minus_tmp);
	minus_tmp = normalize(minus_tmp);
	ray_light.ray_dir = minus_tmp;
	ray_light.ray_orig = ft_plus(data->rays.p, ft_mult(0.01, data->rays.n));
	shadow = routine_inter(data, &ray_light);
	if (shadow && ray_light.t * ray_light.t < dot_light)
			ray_light.col = add_values(data->rays.col.x * data->light->ratio
				* (data->light->color.x / 255), data->rays.col.y
				* data->light->ratio * (data->light->color.y / 255),
				data->rays.col.z * data->light->ratio
				* (data->light->color.z / 255));
	else
		ray_light.col = data->rays.col;
	return (ray_light.col);
}

t_light	*light_details(t_data *data, t_light *c_light)
{
	c_light = data->light;
	if (c_light && c_light->type != 'L')
		c_light = c_light->next;
	return (c_light);
}
/*
	//ray_light.ray_orig = ft_plus(data->rays.p, ft_mult(0.01, data->rays.n));
	// rays->light.intens_pixel = ft_mult((rays->light.l_bright \
	// 	* ft_max(dot(minus_tmp, rays->light.n)) / dot_light), rays->light.albedo);
	//add_amb(data, &ray_light);
*/