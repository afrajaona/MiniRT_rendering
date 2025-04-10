/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:56:47 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 11:19:48 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void compute_pixel(double ndc_x, double ndc_y, t_objects obj, int *color)
{
	t_ray		ray;
	t_vector	ray_dir;
	t_obj_attr	hit;

	ray_dir = norm((t_vector){ndc_x, ndc_y, 1});
	ray.origin = obj.camera.sys.origine;
	ray.direction = ray_dir;

	if (find_nearest_hit(ray, obj, &hit))
	{
		if (hit.type == SPHERE)
			compute_sphere(hit, obj, ray, color);
		else if (hit.type == PLANE)
			compute_plane(hit, obj, ray, color);
		else if (hit.type == CYLINDER)
			compute_cylinder(hit, obj, ray, color);
	}
}