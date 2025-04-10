/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:29:12 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 14:13:36 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static double	calculate_sphere_disc(t_ray ray, t_sphere sphere)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;

	oc = substraction(ray.origin, sphere.sys.origine);
	a = scalar_product(ray.direction, ray.direction);
	b = 2.0 * scalar_product(oc, ray.direction);
	c = scalar_product(oc, oc) - pow(sphere.diametre / 2, 2);
	return (b * b - 4 * a * c);
}

int	sphere_intersection(t_ray ray, t_sphere obj, t_obj_attr	*sphere)
{
	double	b;
	double	t0;
	double	t1;
	double	discriminant;

	discriminant = calculate_sphere_disc(ray, obj);
	if (discriminant < 0)
		return (0);
	b = 2.0 * (scalar_product
			(substraction(ray.origin, obj.sys.origine), ray.direction));
	t0 = ((-b - sqrt(discriminant)) / 2.0);
	t1 = ((-b + sqrt(discriminant)) / 2.0);
	if (t0 > 0)
		sphere->scalar = t0;
	else
		sphere->scalar = t1;
	if (sphere->scalar <= 0)
		return (0);
	sphere->normal = norm(
				substraction(
					addition(ray.origin,
						multiplication(ray.direction, sphere->scalar)),
					obj.sys.origine));
	sphere->type = SPHERE;
	return (1);
}