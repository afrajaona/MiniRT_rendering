/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:16:24 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/08 15:13:42 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void free_cylinders(t_cylindres *t)
{
  if (t)
  {
    free(t->member);
    free(t);
  }
}

void free_planes(t_planes *t)
{
  if (t)
  {
    free(t->member);
    free(t);
  }
}

void free_spheres(t_spheres *t)
{
  if (t)
  {
    free(t->member);
    free(t);
  }
}

void ft_free_objects(t_objects *o)
{
  free_spheres(o->spheres);
  free_planes(o->planes);
  free_cylinders(o->cylindres);
}
