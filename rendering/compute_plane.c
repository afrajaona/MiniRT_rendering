/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:00:40 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 16:37:23 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "struct.h"

void	compute_plane(t_obj_attr plane, t_objects obj, t_ray ray, int *color)
{
	t_vector	hit_point;
	t_vector	lighting;
	t_color		colour;
	double		intensity;

	hit_point = addition(obj.camera.sys.origine,
			multiplication(ray.direction, plane.scalar));
	colour = obj.planes->member->color;
	lighting = norm(substraction(obj.light.sys.origine, hit_point));
	intensity = fmax(0, scalar_product(plane.normal, lighting));
	compute_lighting(color, intensity, colour, obj);
}
