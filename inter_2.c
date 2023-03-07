/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:14:38 by nnemeth           #+#    #+#             */
/*   Updated: 2023/03/07 16:55:00 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	inter_sphere(t_data *data, t_form *current, t_rays *ray)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vector	oc;

	oc = minus(ray->ray_orig, current->coord);
	a = dot(ray->ray_dir, ray->ray_dir);
	b = 2.0f * (dot(oc, ray->ray_dir));
	c = dot(oc, oc) - (current->sphere_rad * current->sphere_rad);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	ray->t1 = (-b + sqrt(delta)) / (2 * a);
	ray->t2 = (-b - sqrt(delta)) / (2 * a);
	if (ray->t2 > ray->t && ray->t1 > ray->t)
		return (FALSE);
	if (ray->t2 > 0 && ray->t2 < ray->t1)
		ray->t = ray->t2;
	else if (ray->t1 > 0)
		ray->t = ray->t1;
	else
		return(FALSE);
	hit_point(data, current, ray);
	return (TRUE);
}

int	hit_point(t_data *data, t_form *current, t_rays *ray)
{
	t_light		*c_light;
	t_light		*a_light;
	float		d;

	ray->p = (ft_plus((ray->ray_orig), ft_mult(ray->t,
					ray->ray_dir)));
	ray->hit_id = current->id;
	c_light = data->light;
	a_light = data->light;
	while (c_light && c_light->type != 'L')
		c_light = c_light->next;
	while (a_light && a_light->type != 'A')
		a_light = a_light->next;
	if (!c_light || !a_light)
		return (FALSE);
	c_light->light_dir = minus(ray->p, c_light->coord);
	ray->n = normalize((minus(ray->p, current->coord)));
	c_light->light_dir = normalize(c_light->light_dir);
	d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
	ray->col = ft_mult(d, current->color);
	//ray->col = add_values(a_light->color.x, a_light->color.y, a_light->color.z);
	ray->col = add_values(ray->col.x * a_light->ratio
		* (a_light->color.x / 255) / d, ray->col.y
		* a_light->ratio * (a_light->color.y / 255) / d,
		ray->col.z * a_light->ratio
		* (a_light->color.z / 255) / d);
	return (TRUE);
}

int	inter_plane(t_data *data, t_form *current, t_rays *ray)
{
	float		denom;
	t_vector	oc;
	float		t;

	current->orient = normalize(current->orient);
	denom = dot(ray->ray_dir, current->orient);
	oc = minus(current->coord, ray->ray_orig);
	t = dot(oc, current->orient) / denom;
	if (t < 0)
		return (FALSE);
	if (t < ray->t)
		ray->t = t;
	else
		return (FALSE);
	if (t > 0.0)
	{
		plane_found(data, current, ray);
		return (TRUE);
	}
	return (FALSE);
}

int	plane_found(t_data *data, t_form *current, t_rays *ray)
{
	float		d;
	t_light		*c_light;

	c_light = data->light;
	if (c_light && c_light->type != 'L')
		c_light = c_light->next;
	if (!c_light)
		return (FALSE);
	ray->p = (ft_plus((ray->ray_orig),
				ft_mult(ray->t, ray->ray_dir)));
	ray->n = current->orient;
	c_light->light_dir = normalize(minus(ray->p, c_light->coord));
	d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
	if (d < 0)
		d *= -1;
	ray->col = ft_mult(d, current->color);
	ray->hit_id = current->id;
	return (TRUE);
}
