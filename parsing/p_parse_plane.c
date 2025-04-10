/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:05:45 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 14:30:09 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int valid_plane_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error: invalid plane element number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1])
  	|| !valid_vec(e[2])
    || !valid_vec(e[3]))
		return (ft_putendl_fd("Error : invalid plane element(2)", 2), 0);
	return (1);
}

int construct_plane(t_objects *o, int j, char **elements)
{
  t_vector    p;

  if (!valid_plane_lineup(elements))
    return (ft_free(elements), -1);
  assign_vec(&o->planes->member[j].pt, elements[1]);
  assign_vec(&o->planes->member[j].normal, elements[2]);
  assign_vec(&p, elements[3]);
  ft_free(elements);
  if (!p_in_range(p.x, 0, 255)
    || !p_in_range(p.y, 0, 255)
    || !p_in_range(p.z, 0, 255)
    || !p_in_range(o->planes->member[j].normal.x, -1, 1)
    || !p_in_range(o->planes->member[j].normal.y, -1, 1)
    || !p_in_range(o->planes->member[j].normal.z, -1, 1))
    return (ft_putendl_fd("Error : out of range plane element value", 2), -1);
  o->planes->member[j].color = (t_color){p.x, p.y, p.z};
  return (0);
}

int parse_plane(char *line, t_objects *o)
{
  static int j = 0;
  t_plane   *temp;
	char		   **elements;
	int			   i;

	i = -1;
  if (!j)
  {
    o->planes = ft_calloc(1, sizeof(t_planes));
    o->planes->member = ft_calloc(2, sizeof(t_plane));
  }
  else
  {
    temp = ft_calloc(j + 2, sizeof(t_plane));
    while (++i < j)
      temp[i] = o->planes->member[i];
    free(o->planes->member);
    o->planes->member = temp;
  }
  elements = ft_split(line, ' ');
  if (construct_plane(o, j, elements))
    return (ft_free_objects(o), -1);
  j++;
  o->planes->nb = j;
	return (0);
}
