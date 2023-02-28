/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/28 15:30:26 by fmalizia         ###   ########.ch       */
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
	t_light		*c_light;
	float 		d;

	oc = minus(ray->ray_orig, current->coord);
	a = dot(ray->ray_dir, ray->ray_dir);
	b = 2.0f * (dot(oc, ray->ray_dir));
	c = dot(oc, oc) - (current->sphere_rad * current->sphere_rad);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	ray->t1 = (-b + sqrt(delta)) / (2 * a);
	ray->t2 = (-b - sqrt(delta)) / (2 * a);
	if (ray->t2 > ray->t)
		return (FALSE);
	if (ray->t1 < 0)
		return (FALSE);
	if (ray->t2 > 0)
		ray->t = ray->t2;
	else
		ray->t = ray->t1;
	ray->p = (ft_plus((ray->ray_orig), ft_mult(ray->t,
					ray->ray_dir)));
	ray->hit_id = current->id;
	c_light = data->light;
	if ( c_light && c_light->type != 'L')
		c_light = c_light->next;
	if (!c_light)
		return(FALSE);
	c_light->light_dir = minus(ray->p, c_light->coord);
	ray->n = normalize((minus(ray->p, current->coord)));
	c_light->light_dir = normalize(c_light->light_dir);
	d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
	ray->n = ft_mult(d, current->color);

	return (TRUE);
}
/*need to fix the light part for the end to work*/

//www.google.com/search?q=rendering+a+sphere+in+c+language&oq=
//rendering+a+sphere+in+c+&aqs=chrome.3.69i57j33i160l3.9737j1j7&sourceid=chrome&
//ie=UTF-8#fpstate=ive&vld=cid:86a89d49,vid:v9vndyfk2U8

int	inter_plane(t_data *data, t_form *current, t_rays *ray)
{
	float		denom;
	t_vector	oc;
	float		t;
	t_light		*c_light;
	float 		d;

	current->orient = normalize(current->orient);
	denom = dot(ray->ray_dir, current->orient);
	oc = minus(ray->ray_orig, current->coord);
	t = (-1 * dot(oc, current->orient)) / denom;
	if (t < 0)
		return (FALSE);
	if (t < ray->t)
		ray->t = t;
	else
		return (FALSE);
	if (t >= 0.0)
	{
		c_light = data->light;
		if ( c_light && c_light->type != 'L')
			c_light = c_light->next;
		if (!c_light)
			return(FALSE);
		ray->p = (ft_plus((ray->ray_orig),
					ft_mult(ray->t, ray->ray_dir)));
		ray->n = current->orient;
		c_light->light_dir = minus(ray->p, c_light->coord);
		// ray->n = normalize((minus(ray->p, current->orient)));
		c_light->light_dir = normalize(c_light->light_dir);
		d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
		ray->n = ft_mult(d, current->color);
		ray->hit_id = current->id;
		return (TRUE);
	}
	return (FALSE);
}

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
	if (ray->t2 > ray->t || ray->t1 < 0)
		return (FALSE);
	if (ray->t2 > 0)
		ray->t = ray->t2;
	else
		ray->t = ray->t1;
	ray->p = (ft_plus((ray->ray_orig),
				ft_mult(ray->t, ray->ray_dir)));
	m = (dot(ray->ray_dir, current->orient) * ray->t)
		+ dot(oc, current->orient);
	if (m < 0 || m > current->cyl_height)
	{
		ray->t = t_tmp;
		return (FALSE);
	}
	vm = ft_mult(m, current->orient);
	c_light = data->light;
	if ( c_light && c_light->type != 'L')
		c_light = c_light->next;
	if (!c_light)
		return(FALSE);
	c_light->light_dir = minus(ray->p, c_light->coord);
	ray->n = normalize(minus(minus(ray->p, current->coord), vm));
	c_light->light_dir = normalize(c_light->light_dir);
	d = (dot(ray->n, ft_mult(-1, c_light->light_dir)));
	ray->n = ft_mult(d, current->color);
	ray->hit_id = current->id;
	return (TRUE);
}
/*take light calculation and put it in its own function*/

int	routine_inter(t_data *data, t_rays *ray)
{
	t_form	*curr;
	int		hit;

	hit = FALSE;
	ray->t = 1E99;
	ray->t1 = 100000;
	ray->t2 = 100000;
	curr = data->object;
	while (curr)
	{
		if (data->rays.hit_id == curr->id)
		{
			curr = curr->next;
			continue;
		}
		if (curr->type == 'S')
		{
			if (inter_sphere(data, curr, ray))
				hit = TRUE;
		}
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
