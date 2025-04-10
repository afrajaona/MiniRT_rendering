/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:56:22 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:24 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int valid_sphere_lineup(char **e)
{
	int	i;

	i = 0;
	while(e[i])
		i++;
	if (i != 4)
	{
		ft_putendl_fd("Error: invalid sphere element number(1)", 2);
		return (0);
	}
	if (ft_strlen(e[0]) != 2)
		return (ft_putstr_fd("Error : ", 2), ft_putendl_fd(e[0], 2), 0);
	if (!valid_vec(e[1])
  	|| !valid_double(e[2])
    || !valid_vec(e[3]))
		return (ft_putendl_fd("Error : invalid sphere element(2)", 2), 0);
	return (1);
}

int construct_sphere(t_objects *o, int j, char **elements)
{
  t_vector    p;

  if (!valid_sphere_lineup(elements))
    return (ft_free(elements), -1);
  assign_vec(&o->spheres->member[j].sys.origine, elements[1]);
  o->spheres->member[j].diametre = ft_atod(elements[2]);
  assign_vec(&p, elements[3]);
  ft_free(elements);
  if (!p_in_range(p.x, 0, 255)
    || !p_in_range(p.y, 0, 255)
    || !p_in_range(p.z, 0, 255))
    return (ft_putendl_fd("Error : out of range sphere element value", 2), -1);
  o->spheres->member[j].color = (t_color){p.x, p.y, p.z};
  return (0);
}

int parse_sphere(char *line, t_objects *o)
{
  static int j = 0;
  t_sphere   *temp;
	char		   **elements;
	int			   i;

	i = -1;
  if (!j)
  {
    o->spheres = ft_calloc(1, sizeof(t_spheres));
    o->spheres->member = ft_calloc(2, sizeof(t_sphere));
  }
  else
  {
    temp = ft_calloc(j + 2, sizeof(t_sphere));
    while (++i < j)
      temp[i] = o->spheres->member[i];
    free(o->spheres->member);
    o->spheres->member = temp;
  }
  elements = ft_split(line, ' ');
  if (construct_sphere(o, j, elements))
    return (ft_free_objects(o), -1);
  j++;
  o->spheres->nb = j;
	return (0);
}
