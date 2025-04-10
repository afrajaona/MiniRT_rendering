/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:01:37 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/04 13:38:14 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	p_error(char *s)
{
	ft_putstr_fd("error in parsing ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(" elements", 2);
}
int	p_in_range(int value, int inf, int max)
{
	return (value >= inf && value <= max);
}

void	file_check(int ac, char *filename)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		ft_putendl_fd("Wrong number of arguments !", 2);
		exit (1);
	}
	while (filename[i])
		i++;
	if (ft_strncmp(&filename[i - 3], ".rt", 3))
	{
		ft_putendl_fd("File has to be suffixed .rt", 2);
		exit (1);
	}
}

void init_objects(t_objects *base)
{
	base->no_camera = 1;
	base->no_light = 1;
	base->spheres = NULL;
	base->planes = NULL;
	base->cylindres = NULL;
}

void	check_emptiness(t_objects *base)
{
		if(base->no_camera || base->no_light
			||!base->spheres || !base->planes || !base->cylindres)
		{
			ft_free_objects(base);
			ft_putendl_fd("Missing identifier", 2);
			exit(1);
		}
}

int	parse_call(char *line, int i, t_objects *base)
{
	int	ret;

	if (line[i] == 'C')
		ret = parse_camera(line, base);
	else if (line[i] == 'L')
		ret = parse_light(line, base);
	else if (!ft_strncmp(line, "sp", 2))
		ret = parse_sphere(line, base);
	else if (!ft_strncmp(line, "pl", 2))
		ret = parse_plane(line, base);
	else if (!ft_strncmp(line, "cy", 2))
		ret = parse_cylinder(line, base);
	else if (!line[i] || line[i] == '\n')
		ret = 0;
	else
	{
		ft_putendl_fd("error: found unexpected identifier", 2);
		ret = -1;
	}
	return (ret);
}

void	parse(int ac, char	*filename, t_objects *base)
{
	int		fd;
	int		i;
	char	*line;

	file_check(ac, filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	init_objects(base);
	while (line)
	{
		while (line[i] && line[i] == ' ' && line[i] != '\n')
			i++;
		if (parse_call(line, i, base))
			exit(printf("failure"));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_emptiness(base);
}
