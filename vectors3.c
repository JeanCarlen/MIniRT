/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:55:57 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/15 13:58:54 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_vector	ft_mult_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}

t_vector	add_values(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector	cross(t_vector vect_a, t_vector vect_b)
{
	t_vector	res;

	res.x = vect_a.y * vect_b.z - vect_a.z * vect_b.y;
	res.y = vect_a.z * vect_b.x - vect_a.x * vect_b.z;
	res.z = vect_a.x * vect_b.y - vect_a.y * vect_b.x;
	return (res);
}

void	print_vec(char *str, t_vector v)
{
	if (str)
		printf("%s", str);
	printf("%f %f %f\n", v.x, v.y, v.z);
}
