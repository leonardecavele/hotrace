/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:58:42 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:33:30 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>

# include "error.h"

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
	ssize_t	nread;
	size_t	cur;
	size_t	max;
}	t_gnl;

t_errcode	get_next_line_no_nl(int fd, char **s);
void		ft_putstr_fd(int fd, const char *s);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);

#endif
