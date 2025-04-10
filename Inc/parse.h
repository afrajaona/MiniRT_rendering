/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:07:56 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/03 15:40:01 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"
# include <math.h>
# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

void	assign_vec(t_point	*p, char *s);
void  ft_free(char **tab);
void  ft_free_objects(t_objects *o);
void	parse(int ac, char	*filename, t_objects *base);
int		p_in_range(int value, int inf, int max);
void	p_error(char *s);
int 	parse_camera(char *s, t_objects *o);
int		p_vec(char *s, int *i, t_point *o, char *bloc);
int 	parse_cylinder(char *s, t_objects *o);
int		parse_light(char *s, t_objects *o);
int 	p_double(char *s, int *i, double *o, char *err);
int 	parse_plane(char *s, t_objects *o);
int 	parse_sphere(char *s, t_objects *o);
int	  valid_double(char *s);
int	  valid_vec(char *s);
double  ft_atod(char *s);

#endif
