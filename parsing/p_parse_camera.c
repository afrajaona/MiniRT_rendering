/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:31:25 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:33:24 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_cam_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 4)
	{
		i = 0;
		while (e[i])
			printf("%s\n", e[i++]);
		ft_putendl_fd("Error: invalid camera element number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 1)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1])
		|| !valid_vec(e[2])
		|| !valid_double(e[3]))
		return (ft_putendl_fd("Error : invalid camera element(2)", 2), 0);
	return (1);
}

int	parse_camera(char *line, t_objects	*o)
{
	static int	func_call = 0;
	char		**elements;

	if (func_call)
		return (ft_putendl_fd("No more than one C", 2), -1);
	elements = ft_split(line, ' ');
	if (!valid_cam_lineup(elements))
		return (ft_free_objects(o), ft_free(elements), -1);
	assign_vec(&o->camera.sys.origine, elements[1]);
	assign_vec(&o->camera.normal, elements[2]);
	o->camera.fov = ft_atod(elements[3]);
	ft_free(elements);
	if (!p_in_range(o->camera.normal.x, -1, 1)
		|| !p_in_range(o->camera.normal.y, -1, 1)
		|| !p_in_range(o->camera.normal.z, -1, 1)
		|| !p_in_range(o->camera.fov, 0, 180))
	{
		ft_free_objects(o);
		return (ft_putendl_fd("Error : out of range camera element value", 2), -1);
	}
	func_call++;
	o->no_camera = 0;
	return (0);
}
