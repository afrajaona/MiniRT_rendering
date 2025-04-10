/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyrandri <nyrandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:16:30 by nyrandri          #+#    #+#             */
/*   Updated: 2025/03/03 12:17:16 by nyrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		mlx_loop_end(data->mlx);
	return (0);
}

void	event(t_data *data)
{
	// Cliquer sur la croix en haut a droite fait fermer la fenetre
	mlx_hook(data->mlx_win, 17, 0, &mlx_loop_end, data->mlx);
	mlx_key_hook(data->mlx_win, &close_window, data);
}
