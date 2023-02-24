/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/24 18:05:04 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	inter_sphere(t_data *data, t_form *current)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vector	oc;
	float 		d;

	oc = minus(data->rays.ray_orig, current->coord);
	a = dot(data->rays.ray_dir, data->rays.ray_dir);
	b = 2.0f * (dot(oc, data->rays.ray_dir));
	c = dot(oc, oc) - (current->sphere_rad * current->sphere_rad);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	data->rays.t1 = (-b + sqrt(delta)) / (2 * a);
	data->rays.t2 = (-b - sqrt(delta)) / (2 * a);
	if (data->rays.t2 > data->rays.t)
		return (FALSE);
	if (data->rays.t1 < 0)
		return (FALSE);
	if (data->rays.t2 > 0)
		data->rays.t = data->rays.t2;
	else
		data->rays.t = data->rays.t1;
	data->rays.p = (ft_plus((data->rays.ray_orig), ft_mult(data->rays.t,
					data->rays.ray_dir)));
	data->rays.n = normalize((minus(data->rays.p, current->coord)));
	data->light->light_dir = normalize(data->light->light_dir);
	d = (dot(data->rays.n, ft_mult(-1, data->light->light_dir)));
	data->rays.n = ft_mult(d, current->color);
	return (TRUE);
}
/*need to fix the light part for the end to work*/

//www.google.com/search?q=rendering+a+sphere+in+c+language&oq=
//rendering+a+sphere+in+c+&aqs=chrome.3.69i57j33i160l3.9737j1j7&sourceid=chrome&
//ie=UTF-8#fpstate=ive&vld=cid:86a89d49,vid:v9vndyfk2U8

int	inter_plane(t_data *data, t_form *current)
{
	float		denom;
	t_vector	oc;
	float		t;

	current->orient = normalize(current->orient);
	denom = dot(data->rays.ray_dir, current->orient);
	oc = minus(data->rays.ray_orig, current->coord);
	t = (-1 * dot(oc, current->orient)) / denom;
	if (t < 0)
		return (FALSE);
	if (t < data->rays.t)
		data->rays.t = t;
	else
		return (FALSE);
	if (t >= 0.0)
	{
		data->rays.p = (ft_plus((data->rays.ray_orig),
					ft_mult(data->rays.t, data->rays.ray_dir)));
		data->rays.n = current->orient;
		// d = (dot(data->rays.n, ft_mult(-1, rays->light.light_dir)));
		// data->rays.n = ft_mult(d, rays->light.albedo);
		normalize((minus(data->rays.p, current->orient)));
		return (TRUE);
	}
	return (FALSE);
}

int	inter_cylinder(t_data *data, t_form *current)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		m;
	float		d;
	float		t_tmp;
	t_vector	vm;
	t_vector	oc;

	oc = minus(data->rays.ray_orig, current->coord);
	current->orient = normalize(current->orient);
	a = dot(data->rays.ray_dir, data->rays.ray_dir)
		- powf(dot(data->rays.ray_dir, current->orient), 2);
	b = 2.0f * (dot(data->rays.ray_dir, oc) - (dot(data->rays.ray_dir, \
		current->orient) * dot(oc, current->orient)));
	c = dot(oc, oc) - powf(dot(oc, current->orient), 2)
		- powf(current->cyl_dia / 2, 2);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	data->rays.t1 = (-b + sqrt(delta)) / (2 * a);
	data->rays.t2 = (-b - sqrt(delta)) / (2 * a);
	t_tmp = data->rays.t;
	if (data->rays.t2 > data->rays.t || data->rays.t1 < 0)
		return (FALSE);
	if (data->rays.t2 > 0)
		data->rays.t = data->rays.t2;
	else
		data->rays.t = data->rays.t1;
	data->rays.p = (ft_plus((data->rays.ray_orig),
				ft_mult(data->rays.t, data->rays.ray_dir)));
	m = (dot(data->rays.ray_dir, current->orient) * data->rays.t)
		+ dot(oc, current->orient);
	if (m < 0 || m > current->cyl_height)
	{
		data->rays.t = t_tmp;
		return (FALSE);
	}
	vm = ft_mult(m, current->orient);
	data->rays.n = normalize(minus(minus(data->rays.p, current->coord), vm));
	data->light->light_dir = normalize(data->light->light_dir);
	d = (dot(data->rays.n, ft_mult(-1, data->light->light_dir)));
	data->rays.n = ft_mult(d, current->color);
	return (TRUE);
}

int	routine_inter(t_data *data)
{
	t_form	*curr;
	int		hit;

	hit = FALSE;
	data->rays.t = 1E99;
	data->rays.t1 = 100000;
	data->rays.t2 = 100000;
	curr = data->object;
	while (curr)
	{
		if (curr->type == 'S')
		{
			if (inter_sphere(data, curr))
				hit = TRUE;
		}
		if (curr->type == 'P')
			if (inter_plane(data, curr))
				hit = TRUE;
		if (curr->type == 'C')
			if (inter_cylinder(data, curr))
				hit = TRUE;
		curr = curr->next;
	}
	return (hit);
}
