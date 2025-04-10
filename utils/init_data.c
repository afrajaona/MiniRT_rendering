/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:19:37 by nyrandri          #+#    #+#             */
/*   Updated: 2025/03/03 09:39:11 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	init_image(t_data *data)
{
	if (data->image.img == NULL)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		return (-1);
	}
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, \
									&data->image.ln_len, &data->image.end);
	if (data->image.addr == NULL)
	{
		mlx_destroy_image(data->mlx, data->image.img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		return (-1);
	}
	return (1);
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH_WIN, LENGTH_WIN, "miniRT");
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx);
		return (-1);
	}
	data->image.img = mlx_new_image(data->mlx, WIDTH_WIN, LENGTH_WIN);
	return (init_image(data));
}
