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
	t_form	*curr;

	data->mlx.win_i = 0;
	curr = data->object;
	data->light->light_dir.x = 0;
	data->light->light_dir.y = 0;
	data->light->light_dir.z = -1;
	while (data->mlx.win_i < H)
	{
		data->mlx.win_y = 0;
		while (data->mlx.win_y < W)
		{
			
			set_scene(data);
			data->rays.hit_id = 0;
			// data->rays.n = add_values(150, 0, 10);
			if (routine_inter(data, &(data->rays)))
			{
				data->rays.n = get_light(data);
				// data->rays.n = add_amb(data);
				my_mlx_pixel_put(data, data->mlx.win_y, (H - data->mlx.win_i - 1),
					color(ft_max(data->rays.n.x),
						ft_max(data->rays.n.y), ft_max(data->rays.n.z)));
			}
			// my_mlx_pixel_put(rays, data->mlx.win_y, (H - data->mlx.win_i - 1),
			// 	color((ft_max(rays->light.intens_s   pixel.x)),
			// 		(ft_max(rays->light.intens_pixel.y)),
			// 		(ft_max(rays->light.intens_pixel.z))));
			data->mlx.win_y++;
		}
		data->mlx.win_i++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img, 0, 0);
}

t_vector	add_amb(t_data *data)
{
	data->rays.n.x *= (data->light->color.x \
	* data->light->ratio) ;
	data->rays.n.y *= (data->light->color.y \
	* data->light->ratio) ;
	data->rays.n.z *= (data->light->color.z \
	* data->light->ratio) ;
	return (data->rays.n);
}

t_vector	get_light(t_data *data)
{
	double		dot_light;
	t_vector	minus_tmp;
	// t_vector	change;
	t_rays		ray_light;
	int			shadow;

	// change.x = 1;
	// change.y = 1;
	// change.z = 1;
	shadow = FALSE;
	minus_tmp = minus(data->light->coord, data->rays.p);
	dot_light = getnorm(minus_tmp);
	minus_tmp = normalize(minus_tmp);
	ray_light.ray_orig = ft_plus(data->rays.p, ft_mult(0.01, data->rays.n));
	ray_light.ray_dir = minus_tmp;
	// ray_light.ray_orig = data->rays.p;
	shadow = routine_inter(data, &ray_light);
	if (shadow && ray_light.t * ray_light.t < dot_light)
		ray_light.n = add_values(0, 0, 0);
	else
		ray_light.n = data->rays.n;
	// rays->light.intens_pixel = ft_mult((rays->light.l_bright \
	// 	* ft_max(dot(minus_tmp, rays->light.n)) / dot_light), rays->light.albedo);
	// rays->light.intens_pixel = normalize(rays->light.intens_pixel);
	// rays->light.intens_pixel = ft_mult_vec(rays->light.albedo, rays->light.intens_pixel);
	return (ray_light.n);
}

/* 
1) create a new ray from the surface to the light]
2) check if the ray intersects with any object
3) if there is an intersection, and the t2 is less than dot light, there is a shade
4) send a black pixel 
*/