/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/13 17:19:19 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	inter_cylinder(t_data *data, t_form *current, t_rays *ray)
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
	t_light		*c_light;

	oc = minus(ray->ray_orig, current->coord);
	current->orient = normalize(current->orient);
	a = dot(ray->ray_dir, ray->ray_dir)
		- powf(dot(ray->ray_dir, current->orient), 2);
	b = 2.0f * (dot(ray->ray_dir, oc) - (dot(ray->ray_dir, \
		current->orient) * dot(oc, current->orient)));
	c = dot(oc, oc) - powf(dot(oc, current->orient), 2)
		- powf(current->cyl_dia / 2, 2);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	ray->t1 = (-b + sqrt(delta)) / (2 * a);
	ray->t2 = (-b - sqrt(delta)) / (2 * a);
	t_tmp = ray->t;
	if (ray->t2 > ray->t)
		return (FALSE);
	if (ray->t2 > 0 && ray->t2 < ray->t1)
		ray->t = ray->t2;
	else if (ray->t1 > 0)
		ray->t = ray->t1;
	else
		return (FALSE);
	ray->p = (ft_plus((ray->ray_orig),
				ft_mult(ray->t, ray->ray_dir)));
	m = (dot(ray->ray_dir, current->orient) * ray->t)
		+ dot(oc, current->orient);
	if (m < 0 || m > current->cyl_height)
	{
		m = (dot(ray->ray_dir, current->orient) * ray->t1)
			+ dot(oc, current->orient);
		if (m < 0 || m > current->cyl_height)
		{
			ray->t = t_tmp;
			return (FALSE);
		}
		ray->t = ray->t1;
	}
	vm = ft_mult(m, current->orient);
	c_light = get_light_type(data->light, 'L');
	if (!c_light)
		return (FALSE);
	c_light->light_dir = minus(ray->p, c_light->coord);
	ray->n = normalize(minus(minus(ray->p, current->coord), vm));
	c_light->light_dir = normalize(c_light->light_dir);
	d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
	if (d < 0)
		d *= -1;
	ray->col = ft_mult(d, current->color);
	ray->hit_id = current->id;
	return (TRUE);
}
/*take light calculation and put it in its own function*/

int	routine_inter(t_data *data, t_rays *ray)
{
	t_form	*curr;
	int		hit;

	hit = FALSE;
	init_t(ray);
	curr = data->object;
	while (curr)
	{
		if (curr->type == 'S')
			if (inter_sphere(data, curr, ray))
				hit = TRUE;
		if (curr->type == 'P')
			if (inter_plane(data, curr, ray))
				hit = TRUE;
		if (curr->type == 'C')
			if (inter_cylinder(data, curr, ray))
				hit = TRUE;
		curr = curr->next;
	}
	return (hit);
}
