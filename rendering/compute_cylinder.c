/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:00:57 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 17:30:04 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	compute_cylinder(t_obj_attr cyl, t_objects obj, t_ray ray, int *color)
{
	t_vector	hit_point;
	t_vector	lighting;
	t_color		colour;
	double		intensity;

	hit_point = addition(obj.camera.sys.origine,
			multiplication(ray.direction, cyl.scalar));
	colour = obj.planes->member[0].color;
	lighting = norm(substraction(obj.light.sys.origine, hit_point));
	if (scalar_product(cyl.normal, lighting) < 0)
		cyl.normal = multiplication(cyl.normal, -1);
	intensity = fmax(0, scalar_product(cyl.normal, lighting));
	if (is_in_shadow(hit_point, obj, 
		norm(substraction(obj.light.sys.origine, hit_point)),
		mag(substraction(obj.light.sys.origine, hit_point))))
		intensity *= 0.3;
	compute_lighting(color, intensity, colour, obj);
}
