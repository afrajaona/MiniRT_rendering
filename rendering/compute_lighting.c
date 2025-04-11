/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:31:11 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 16:32:15 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	compute_lighting(int *color, double intense, t_color t, t_objects o)
{
	t_color	diffuse;
	t_color	ambient;
	t_color	final;

	diffuse = t;
	diffuse.r *= intense * o.light.brightness_ratio;
	diffuse.g *= intense * o.light.brightness_ratio;
	diffuse.b *= intense * o.light.brightness_ratio;
	ambient.r = o.ambient.color.r * o.ambient.ratio;
	ambient.g = o.ambient.color.g * o.ambient.ratio; 
	ambient.b = o.ambient.color.b * o.ambient.ratio;
	final.r = fmin(255, diffuse.r + ambient.r);
	final.g = fmin(255, diffuse.g + ambient.g);
	final.b = fmin(255, diffuse.b + ambient.b);
	*color = (final.r << 16) | (final.g << 8) | final.b;
}
