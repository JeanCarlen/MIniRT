/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/15 13:51:17 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	inter_cylinder(t_data *data, t_form *current, t_rays *ray)
{
	float		t_tmp;
	t_vector	oc;

	t_tmp = ray->t;
	if (get_t_cyl(current, ray, &oc) == FALSE)
		return (FALSE);
	if (get_t(ray) == FALSE)
		return (FALSE);
	current->m = (dot(ray->ray_dir, current->orient) * ray->t)
		+ dot(oc, current->orient);
	if (current->m < 0 || current->m > current->cyl_height)
	{
		current->m = (dot(ray->ray_dir, current->orient) * ray->t1)
			+ dot(oc, current->orient);
		if (current->m < 0 || current->m > current->cyl_height)
		{
			ray->t = t_tmp;
			return (FALSE);
		}
		ray->t = ray->t1;
	}
	return (hit_point(data, current, ray));
}

int	get_t(t_rays *ray)
{
	if (ray->t2 > 0 && ray->t2 < ray->t1)
		ray->t = ray->t2;
	else if (ray->t1 > 0)
		ray->t = ray->t1;
	else
		return (FALSE);
	return (TRUE);
}

int	get_t_cyl(t_form *current, t_rays *ray, t_vector *oc)
{
	float		a;
	float		b;
	float		c;
	float		delta;

	*oc = minus(ray->ray_orig, current->coord);
	current->orient = normalize(current->orient);
	a = dot(ray->ray_dir, ray->ray_dir)
		- powf(dot(ray->ray_dir, current->orient), 2);
	b = 2.0f * (dot(ray->ray_dir, *oc) - (dot(ray->ray_dir, \
		current->orient) * dot(*oc, current->orient)));
	c = dot(*oc, *oc) - powf(dot(*oc, current->orient), 2) \
		- powf(current->cyl_dia / 2, 2);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	ray->t1 = (-b + sqrt(delta)) / (2 * a);
	ray->t2 = (-b - sqrt(delta)) / (2 * a);
	if (ray->t2 > ray->t)
		return (FALSE);
	return (TRUE);
}

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
