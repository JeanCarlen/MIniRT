/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:58:16 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 17:50:23 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_vector	ft_mult(double t, t_vector v1)
{
	t_vector	new;

	new.x = t * v1.x;
	new.y = t * v1.y;
	new.z = t * v1.z;
	return (new);
}

double	ft_mult2(t_vector v2, t_vector v1)
{
	return (v2.x * v1.x + v2.y * v1.y + v2.z * v1.z);
}

t_vector	ft_plus(t_vector origin, t_vector position)
{
	t_vector	new;

	new.x = origin.x + position.x;
	new.y = origin.y + position.y;
	new.z = origin.z + position.z;
	return (new);
}

double	ft_max(double clr)
{
	if (clr > 255)
		clr = 255;
	if (clr < 0)
		clr = 0;
	return (clr);
}

t_vector	ft_divide(t_vector v1, double a)
{
	t_vector	new;

	new.x = v1.x / a;
	new.y = v1.y / a;
	new.z = v1.z / a;
	return (new);
}
