/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:48:25 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/11 16:07:55 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int valid_ambient_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 3)
	{
		ft_putendl_fd("Error: invalid ambient element number", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_double(e[1])
  	|| !valid_vec(e[2]))
		return (ft_putendl_fd("Error : invalid ambient element", 2), 0);
	return (1);
}

int invalid_ambient_range(t_ambient a)
{
    return (!p_in_range(a.ratio, 0, 1)
        || !p_in_range(a.color.r, 0, 255)
        || !p_in_range(a.color.g, 0, 255)
        || !p_in_range(a.color.b, 0, 255));
}

int parse_ambient(char *line, t_objects *o)
{
	static int	func_call = 0;
	char		    **elements;
    t_vector    p;

	if (func_call)
	{
		ft_free_objects(o);
			return (ft_putendl_fd("No more than one A", 2), -1);
	}
	elements = ft_split(line, ' ');
	if (!valid_ambient_lineup(elements))
		return (ft_free(elements), -1);
	o->ambient.ratio = ft_atod(elements[1]);
    assign_vec(&p, elements[2]);
    o->ambient.color = (t_color){p.x, p.y, p.z};
	ft_free(elements);
	if (invalid_ambient_range(o->ambient))
	{
		ft_free_objects(o);
		return (ft_putendl_fd("Error : out of range ambient element value", 2), -1);
	}
	func_call++;
	o->no_ambient = 0;
	return (0);
}