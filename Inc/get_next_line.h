/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:45:01 by arajaona          #+#    #+#             */
/*   Updated: 2024/03/15 10:05:47 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h> 

char	*extract_line(char *leftover);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*get_next_line(int fd);
char	*whatsleftover(char *leftover);
int		gnl_strlen(const char *str);

#endif
