/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:11:04 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:14:45 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int valid_cylindre_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 6)
	{
		ft_putendl_fd("Error: invalid cylindre element number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1])
  	|| !valid_vec(e[2])
    || !valid_double(e[3])
    || !valid_double(e[4])
    || !valid_vec(e[5]))
		return (ft_putendl_fd("Error : invalid cylindre element(2)", 2), 0);
	return (-1);
}

int construct_cylindre(t_objects *o, int j, char **elements)
{
  t_vector    p;

  if (!valid_cylindre_lineup(elements))
    return (ft_free(elements), -1);
  assign_vec(&o->cylindres->member[j].center, elements[1]);
  assign_vec(&o->cylindres->member[j].normal, elements[2]);
  o->cylindres->member[j].diametre = ft_atod(elements[3]);
  o->cylindres->member[j].height = ft_atod(elements[4]);
  assign_vec(&p, elements[5]);
  ft_free(elements);
  if (!p_in_range(p.x, 0, 255)
    || !p_in_range(p.y, 0, 255)
    || !p_in_range(p.z, 0, 255)
    || !p_in_range(o->cylindres->member[j].normal.x, -1, 1)
    || !p_in_range(o->cylindres->member[j].normal.y, -1, 1)
    || !p_in_range(o->cylindres->member[j].normal.z, -1, 1))
    return (ft_putendl_fd("Error : out of range cylindre element value", 2), -1);
  o->cylindres->member[j].color = (t_color){p.x, p.y, p.z};
  return (0);
}

int parse_cylinder(char *line, t_objects *o)
{
  static int j = 0;
  t_cylindre   *temp;
	char		   **elements;
	int			   i;

	i = -1;
  if (!j)
  {
    o->cylindres = ft_calloc(1, sizeof(t_cylindres));
    o->cylindres->member = ft_calloc(2, sizeof(t_cylindre));
  }
  else
  {
    temp = ft_calloc(j + 2, sizeof(t_cylindre));
    while (++i < j)
      temp[i] = o->cylindres->member[i];
    free(o->cylindres->member);
    o->cylindres->member = temp;
  }
  elements = ft_split(line, ' ');
  if (construct_cylindre(o, j, elements))
    return (ft_free_objects(o), -1);
  j++;
  o->cylindres->nb = j;
	return (0);
}
