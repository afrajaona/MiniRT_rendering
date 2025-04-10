/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:18 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:10:17 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render(t_data *data, t_objects obj)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	while (++y < LENGTH_WIN)
	{
		x = -1;
		while (++x < WIDTH_WIN)
		{
			color = 0xF0E68C;
			compute_pixel((2.0 * x / WIDTH_WIN - 1.0) * ASPECT_RATIO,
				1.0 - (2.0 * y / LENGTH_WIN),
				obj, &color);
			my_mlx_pixel_put(&data->image, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
}