/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:17:35 by nyrandri          #+#    #+#             */
/*   Updated: 2025/03/29 16:41:06 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_utils.h"

double	norme(t_vector vect)
{
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}

double	scalar_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	mag(t_vector vec)
{
	return (sqrt(scalar_product(vec, vec)));
}

t_vector	norm(t_vector vec)
{
	return ((t_vector){
		vec.x / mag(vec),
		vec.y / mag(vec),
		vec.z / mag(vec)
	});
}

t_vector	substraction(t_vector a, t_vector b)
{
	return ((t_vector){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	});
}

t_vector	addition(t_vector a, t_vector b)
{
	return ((t_vector){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	});
}

t_vector	multiplication(t_vector a, double param)
{
	return ((t_vector){
		a.x * param,
		a.y * param,
		a.z * param
	});
}

t_vector	projection(t_vector v, t_vector axis)
{
	return (multiplication(axis, scalar_product(v, axis)));
}

t_vector	perpendicular(t_vector v, t_vector axis)
{
	return (substraction(v, projection(v, axis)));
}

t_vector	to_vector(t_point pt)
{
	t_vector	vect;

	vect.x = pt.x;
	vect.y = pt.y;
	return (vect);
}
