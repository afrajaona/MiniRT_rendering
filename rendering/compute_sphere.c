/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:58:03 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 13:03:07 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	compute_sphere(t_obj_attr sphere, t_objects obj, t_ray ray, int *color)
{
	t_sphere	temp;
	t_vector	hit_point;
	t_vector	lighting;
	double		intensity;

	temp = obj.spheres->member[obj.spheres->index];
	hit_point = addition(obj.camera.sys.origine,
			multiplication(ray.direction, sphere.scalar));
	lighting = norm(substraction(obj.light.sys.origine, hit_point));
	intensity = fmax(0, scalar_product(sphere.normal, lighting));
	temp.color.r = (int)(temp.color.r * intensity);
	temp.color.g = (int)(temp.color.g * intensity);
	temp.color.b = (int)(temp.color.b * intensity);
	if (temp.color.r > 255)
		temp.color.r = 255;
	if (temp.color.g > 255)
		temp.color.g = 255;
	if (temp.color.b > 255)
		temp.color.b = 255;
	*color = (temp.color.r << 16) | (temp.color.g << 8) | temp.color.b;
}
