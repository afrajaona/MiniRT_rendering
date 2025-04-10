/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:25:31 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/04 15:25:42 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	valid_vec(char *s)
{
	int	i;
	int	count;
	int	dot_count;

	count = -1;
	i = -1;
	while (++count < 3)
	{
		dot_count = 0;
		while (s[++i] && s[i] != ',' && s[i] != '\n')
		{
			if (s[i] == '-' && ft_isdigit(s[i + 1]))
				i++;
			if (!ft_isdigit(s[i]))
			{
				if (s[i] == '.' && ft_isdigit(s[i + 1]))
				{
					if (++dot_count > 1)
						return (printf("%s(1)\n", s), 0);
					i++;
				}
				else
					return (printf("%s(2)\n", s), 0);
			}
		}
		if (!s[i] || s[i] == '\n')
			break ;
		i++;
	}
	if (count != 2)
		return (printf("%s(3)\n", s), 0);
	return (1);
}

int	valid_double(char *s)
{
	int	i;
	int	dot_count;

	i = -1;
	dot_count = 0;
	while (s[++i] && s[i] != '\n')
	{
		if (s[i] == '-' && ft_isdigit(s[i + 1]))
			i++;
		if (!ft_isdigit(s[i]))
		{
			if (s[i] == '.' && ft_isdigit(s[i + 1]))
			{
				if (++dot_count > 1)
					return (printf("%s(4)\n", s), 0);
				i++;
			}
			else
				return (printf("%s(5)\n", s), 0);
		}
	}
	return (1);
}
