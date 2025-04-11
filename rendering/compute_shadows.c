/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_shadows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:21:09 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 17:30:07 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int is_in_shadow(t_vector point, t_objects o, t_vector led, double light_dist)
{
	t_ray       shadow_ray;
	t_obj_attr  shadow_hit;

	shadow_ray.origin = addition(point, multiplication(led, 1e-4));
	shadow_ray.direction = led;
	if (find_nearest_hit(shadow_ray, o, &shadow_hit))
		return (shadow_hit.scalar < light_dist);
	return (0);
}