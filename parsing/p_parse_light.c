/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:31:20 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 14:46:00 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int valid_light_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error: invalid light element number(rgb included)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1])
  	|| !valid_double(e[2]))
		return (ft_putendl_fd("Error : invalid light element", 2), 0);
	return (1);
}

int parse_light(char *line, t_objects *o)
{
	static int	func_call = 0;
	char		    **elements;

	if (func_call)
	{
		ft_free_objects(o);
			return (ft_putendl_fd("No more than one L", 2), -1);
	}
	elements = ft_split(line, ' ');
	if (!valid_light_lineup(elements))
		return (ft_free(elements), -1);
	assign_vec(&o->light.sys.origine, elements[1]);
	o->light.brightness_ratio = ft_atod(elements[2]);
	ft_free(elements);
	if (!p_in_range(o->light.brightness_ratio, 0, 1))
	{
		ft_free_objects(o);
		return (ft_putendl_fd("Error : out of range light element value", 2), -1);
	}
	func_call++;
	o->no_light = 0;
		return (0);
}
