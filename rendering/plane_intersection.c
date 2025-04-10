/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:30:13 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 13:30:49 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	plane_intersection(t_ray ray, t_plane plane, t_obj_attr *attr)
{
	double	denominator;

	denominator = scalar_product(ray.direction, plane.normal);
	if (fabs(denominator) < 1e-6)
		return (0);
	attr->scalar = scalar_product(
			substraction(plane.pt, ray.origin),
			plane.normal) / denominator;
	if (attr->scalar <= 0)
		return (0);
	attr->normal = plane.normal;
	attr->type = PLANE;
	return (1);
}