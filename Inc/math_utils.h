/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:18:07 by nyrandri          #+#    #+#             */
/*   Updated: 2025/03/29 16:39:52 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H

# define MATH_UTILS_H

# include <math.h>
# include "struct.h"

double	    mag(t_vector vec);
double		norme(t_vector vect);
double	    scalar_product(t_vector a, t_vector b);
t_vector	norm(t_vector vec);
t_vector	substraction(t_vector a, t_vector b);
t_vector	addition(t_vector a, t_vector b);
t_vector	multiplication(t_vector a, double param);
t_vector	perpendicular(t_vector v, t_vector axis);
t_vector	projection(t_vector v, t_vector axis);
t_vector	to_vector(t_point pt);

#endif
