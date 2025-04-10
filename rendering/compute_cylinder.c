/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:00:57 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:03:41 by arajaona         ###   ########.fr       */
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
	colour.r = (int)(colour.r * intensity);
	colour.g = (int)(colour.g * intensity);
	colour.b = (int)(colour.b * intensity);
	if (colour.r > 255)
		colour.r = 255;
	if (colour.g > 255)
		colour.g = 255;
	if (colour.b > 255)
		colour.b = 255;
	*color = (colour.r << 16) | (colour.g << 8) | colour.b;
}
