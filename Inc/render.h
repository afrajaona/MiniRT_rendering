/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:27:15 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 17:25:55 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "header.h"
# include "struct.h"
# include "math_utils.h"

void	compute_cylinder(t_obj_attr cyl, t_objects obj, t_ray ray, int *color);
void	compute_lighting(int *color, double intense, t_color t, t_objects o);
void    compute_pixel(double ndc_x, double ndc_y, t_objects obj, int *color);
void	compute_plane(t_obj_attr plane, t_objects obj, t_ray ray, int *color);
void	compute_sphere(t_obj_attr sphere, t_objects obj, t_ray ray, int *color);
void	render(t_data *data, t_objects obj);
int     cylinder_intersection(t_ray ray, t_cylindre cyl, t_obj_attr *data);
int     find_nearest_hit(t_ray ray, t_objects obj, t_obj_attr *closest_hit);
int     is_in_shadow(t_vector point, t_objects o, t_vector led, double light_dist);
int	    plane_intersection(t_ray ray, t_plane plane, t_obj_attr *attr);
int	    sphere_intersection(t_ray ray, t_sphere obj, t_obj_attr	*sphere);

#endif