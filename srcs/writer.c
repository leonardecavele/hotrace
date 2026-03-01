/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:58:42 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:33:30 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "writer.h"

extern void	writer_init(t_writer *writer, int fd, char *buffer, size_t capacity)
{
	writer->fd = fd;
	writer->buffer = buffer;
	writer->capacity = capacity;
	writer->len = 0;
}

extern t_writer	*writer_new(int fd, char *buffer, size_t capacity)
{
	t_writer	*writer;

	writer = malloc(sizeof(t_writer));
	if (!writer)
		return (NULL);
	writer_init(writer, fd, buffer, capacity);
	return (writer);
}

extern void	writer_flush(t_writer *writer)
{
	write(writer->fd, writer->buffer, writer->len);
	writer->len = 0;
	writer->buffer[0] = '\0';
}

extern void	writer_write(t_writer *writer, char *str, size_t len)
{
	size_t	available_size;

	available_size = writer->capacity - writer->len;
	while (len > 0)
	{
		ft_memcpy(writer->buffer + writer->len,
			str, ft_size_min(available_size, len));
		writer->len += ft_size_min(available_size, len);
		str += ft_size_min(available_size, len);
		len -= ft_size_min(available_size, len);
		if (len == 0)
			break ;
		writer_flush(writer);
		available_size = writer->capacity - writer->len;
	}
}
