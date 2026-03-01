/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:58:42 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:33:30 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H

# include <unistd.h>

typedef struct s_writer
{
	size_t	len;
	size_t	capacity;
	char	*buffer;
	int		fd;
}	t_writer;

t_writer	*writer_new(int fd, char *buffer, size_t capacity);
void		writer_flush(t_writer *writer);
void		writer_write(t_writer *writer, char *str, size_t len);
void		writer_init(t_writer *writer,
				int fd, char *buffer, size_t capacity);

#endif