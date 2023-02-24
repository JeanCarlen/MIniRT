/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:27 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 14:05:57 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	load_scene(t_data *data)
{
	t_form	*curr;

	data->mlx.win_i = 0;
	curr = data->object;
	ft_init_window(data);
	data->light->light_dir.x = 2.1;
	data->light->light_dir.y = 5.1;
	data->light->light_dir.z = -2.6;
	while (data->mlx.win_i < H)
	{
		data->mlx.win_y = 0;
		while (data->mlx.win_y < W)
		{
			data->rays.t = 1E99; //max possible value of float
			data->rays.t1 = 100000;
			data->rays.t2 = 100000;
			set_scene(data);
			// data->rays.n = add_values(150, 0, 10);
			if(routine_inter(data))
			{
			// rays->light.n = get_light(rays);
			// data->rays.n = add_amb(data);
				// my_mlx_pixel_put(data, data->mlx.win_y, (H - data->mlx.win_i - 1),
				// 	color(100, 0, 70));
				// printf("%f %f %f\n", data->rays.n.x, data->rays.n.y, data->rays.n.z);
				my_mlx_pixel_put(data, data->mlx.win_y, (H - data->mlx.win_i - 1),
					color(ft_max(data->rays.n.x), ft_max(data->rays.n.y), ft_max(data->rays.n.z)));
			}
			// my_mlx_pixel_put(rays, data->mlx.win_y, (H - data->mlx.win_i - 1),
			// 	color((ft_max(rays->light.intens_s   pixel.x)),
			// 		(ft_max(rays->light.intens_pixel.y)),
			// 		(ft_max(rays->light.intens_pixel.z))));
			data->mlx.win_y++;
		}
		data->mlx.win_i++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img, 0, 0);
}

t_vector	add_amb(t_data *data)
{
	data->rays.n.x *= (data->light->color.x \
	* data->light->ratio);
	data->rays.n.y *= (data->light->color.y \
	* data->light->ratio);
	data->rays.n.z *= (data->light->color.z \
	* data->light->ratio);
	return (data->rays.n);
}

// t_vector	get_light(t_rays *rays)
// {
// 	double		dot_light;
// 	t_vector	minus_tmp;
// 	t_vector	change;
// 	t_vector	ray_light;
// 	int			shadow;

// 	change.x = 1;
// 	change.y = 1;
// 	change.z = 1;
// 	minus_tmp = normalize(minus(rays->light.light_dir, rays->light.p));
// 	dot_light = getnorm(minus_tmp);
// 	ray_light = ft_plus(rays->light.p, ft_mult(0.01, rays->light.n));
// 	shadow = inter_sphere(rays);
// 	if (shadow && rays->t * rays->t < dot_light)
// 		rays->light.n = add_values(0, 0, 0);
// 	// rays->light.intens_pixel = ft_mult((rays->light.l_bright \
// 	// 	* ft_max(dot(minus_tmp, rays->light.n)) / dot_light), rays->light.albedo);
// 	// rays->light.intens_pixel = normalize(rays->light.intens_pixel);
// 	// rays->light.intens_pixel = ft_mult_vec(rays->light.albedo, rays->light.intens_pixel);
// 	return (rays->light.n);
// }
