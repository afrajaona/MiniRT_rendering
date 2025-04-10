/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:33 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/04 15:29:44 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	assign_vec(t_point	*p, char *s)
{
	char	**tab;

	tab = ft_split(s, ',');
	p->x = ft_atod(tab[0]);
	p->y = ft_atod(tab[1]);
	p->z = ft_atod(tab[2]);
	ft_free(tab);
}
