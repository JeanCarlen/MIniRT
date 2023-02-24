/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:19:00 by nikki             #+#    #+#             */
/*   Updated: 2023/02/24 16:09:10 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x
			* (data->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color(double r, double g, double b)
{
	return ((int)r << 16 | (int)g << 8 |(int)b);
}

int	color2(double r, double g, double b)
{
	r *= 255;
	g *= 255;
	b *= 255;
	return (0 << 24 | (int)r << 16 | (int)g << 8 |(int)b);
}

int	ray_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
