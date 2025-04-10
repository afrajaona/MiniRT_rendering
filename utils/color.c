/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:58:43 by nyrandri          #+#    #+#             */
/*   Updated: 2025/03/10 14:41:35 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH_WIN && y >= 0 && y < LENGTH_WIN)
	{
		dst = image->addr + (y * image->ln_len + x * (image->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
