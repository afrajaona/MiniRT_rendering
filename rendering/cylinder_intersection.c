/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:35:18 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 14:41:56 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	valid_discriminant(t_ray ray, t_cylindre cyl, double t[])
{
	t_vector	perp[2];
	double		a;
	double		b;
	double		c;

	perp[0] = perpendicular(ray.direction, cyl.normal);
	perp[1] = perpendicular(substraction(ray.origin, cyl.center), cyl.normal);
	a = scalar_product(perp[0], perp[0]);
	b = 2 * scalar_product(perp[0], perp[1]);
	c = scalar_product(perp[1], perp[1]) - pow(cyl.diametre / 2, 2);
	if ((b * b - 4 * a * c) < 0)
		return (0);
	t[0] = (-b - sqrt(b * b -4 * a * c)) / (2 * a);
	t[1] = (-b + sqrt(b * b -4 * a * c)) / (2 * a);
	return (1);
}

int	body_intersection(t_ray ray, t_cylindre cyl, t_obj_attr *data)
{
	t_vector	hit_point;
	t_vector	axis_proj;
	double		height_proj;
	double		t[2];
	
	if (!valid_discriminant(ray, cyl, t))
		return (0);
	for (int i = 0; i < 2; i++)
	{
		data->scalar = t[i];
		if (t[i] < 0)
			continue ;
		hit_point = addition(ray.origin,
			multiplication(ray.direction, data->scalar));
		axis_proj = substraction(hit_point, cyl.center);
		height_proj = scalar_product(axis_proj, cyl.normal);
		if (fabs(height_proj) <= cyl.height / 2)
		{
			data->normal = norm(perpendicular(axis_proj, cyl.normal));
			return (1);
		}
	}
	data->scalar = -1;
	return (0);
}

void	put_cap(t_ray ray, t_obj_attr *data, t_cylindre cyl, t_cyl_helper h)
{
	t_vector		hit_point;

	hit_point = addition(ray.origin, multiplication(ray.direction, h.t));
	if (mag(substraction(hit_point, h.cap_center)) <= cyl.diametre / 2)
	{
		if (data->scalar < 0 || h.t < data->scalar)
		{
			data->scalar = h.t;
			if (!h.i)
				data->normal = cyl.normal;
			else
				data->normal = multiplication(cyl.normal, -1);
		}
	}
}
int	cap_intersection(t_ray ray, t_cylindre cyl, t_obj_attr *data)
{
	t_cyl_helper	medium;

	medium.i = -1;
	while (++medium.i < 2)
	{
		if (!medium.i)
			medium.cap_center = addition(cyl.center,
			multiplication(cyl.normal, cyl.height / 2));
		else
			medium.cap_center = addition(cyl.center,
			multiplication(cyl.normal, -cyl.height / 2));
		medium.t = scalar_product(substraction(medium.cap_center, ray.origin),
			cyl.normal) / scalar_product(ray.direction, cyl.normal);
		if (medium.t > 0)
			put_cap(ray, data, cyl, medium);
	}
	if (data->scalar < 0)
		return (0);
	return (1);
}

int	cylinder_intersection(t_ray ray, t_cylindre cyl, t_obj_attr *data)
{
	int	hit;

	hit = 0;
	data->scalar = -1;
	cyl.normal = norm(cyl.normal);
	hit |= body_intersection(ray, cyl, data);
	hit |= cap_intersection(ray, cyl, data);
	data->type = CYLINDER;
	return (hit);
}
