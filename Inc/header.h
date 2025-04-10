/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:35:14 by nyrandri          #+#    #+#             */
/*   Updated: 2025/04/08 14:59:13 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

/*************** Include *****************/
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "struct.h"
# include "math_utils.h"
# include "render.h"
# include "parse.h"
# include "libft.h"
# include "get_next_line.h"

/*************** Macro ******************/
# define WIDTH_WIN 1200
# define LENGTH_WIN 700
# define ASPECT_RATIO ((double)WIDTH_WIN / (double)LENGTH_WIN)
# define ESCAPE 65307

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		init_data(t_data *data);
int     cylinder_intersection(t_ray ray, t_cylindre cyl, t_obj_attr *data);
/***************** SUPPRIMATION *******************/

// WARNING: Supprimer cette section avant de push

void	circle(t_data *data, int color);
void	set_backgroung(t_data *data, int color);

/**************************************************/

/****************** EVENT *******************/

int		close_window(int keycode, t_data *data);
void	event(t_data *data);

#endif
