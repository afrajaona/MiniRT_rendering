/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:58:03 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 16:38:17 by arajaona         ###   ########.fr       */
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
	compute_lighting(color, intensity, temp.color, obj);
}
