/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:01:15 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 14:25:17 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	search_sphere(t_ray ray, t_objects obj, t_obj_attr *hit, double *closest)
{
	t_obj_attr	temp;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (++i < obj.spheres->nb)
	{
		if (sphere_intersection(ray, obj.spheres->member[i], &temp)
			&& temp.scalar < *closest)
		{
			*closest = temp.scalar;
			*hit = temp;
			ret = 1;
		}
	}
	return (ret);
}

static int	search_plane(t_ray ray, t_objects obj, t_obj_attr *hit, double *closest)
{
	t_obj_attr	temp;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (++i < obj.planes->nb)
	{
		if (plane_intersection(ray, obj.planes->member[i], &temp)
			&& temp.scalar < *closest)
		{
			*closest = temp.scalar;
			*hit = temp;
			ret = 1;
		}
	}
	return (ret);
}

static int	search_cylinder(t_ray ray, t_objects obj, t_obj_attr *hit, double *closest)
{
	t_obj_attr	temp;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (++i < obj.cylindres->nb)
	{
		if (cylinder_intersection(ray, obj.cylindres->member[i], &temp)
			&& temp.scalar < *closest)
		{
			*closest = temp.scalar;
			*hit = temp;
			ret = 1;
		}
	}
	return (ret);
}

int	find_nearest_hit(t_ray ray, t_objects obj, t_obj_attr *closest_hit)
{
	int		found;
	double	closest;

	closest = INFINITY;
	found = 0;
	found |= search_sphere(ray, obj, closest_hit, &closest);
	found |= search_plane(ray, obj, closest_hit, &closest);
	found |= search_cylinder(ray, obj, closest_hit, &closest);
	return (found);
}
