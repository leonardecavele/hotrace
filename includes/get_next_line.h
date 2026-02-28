/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:37:21 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 13:00:08 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

# define FD_MAX			1024
# define BUFFER_SIZE	1024

typedef struct s_rest
{
	char	b[BUFFER_SIZE];
	size_t	len;
	size_t	i;
}	t_rest;

typedef struct s_gnl
{
	char	*l;
	char	*dup;
	ssize_t	nread;
	size_t	cur;
	size_t	max;
}	t_gnl;

bool	get_next_line(int fd, char **s);

#endif
