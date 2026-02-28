/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_no_nl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:27:10 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 20:11:12 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "error.h"

static void	prep(t_gnl *gnl, t_rest *rest)
{
	*gnl = (t_gnl){0};
	gnl->nread = rest->len;
	if (!rest->len)
		rest->i = 0;
	rest->len = 0;
}

static bool	alloc_l(t_gnl *gnl)
{
	char	*tmp;
	size_t	i;

	if (gnl->nread && !gnl->l)
	{
		gnl->max = gnl->nread;
		gnl->l = malloc(gnl->max + 1);
		if (!gnl->l)
			return (0);
		return (1);
	}
	while (gnl->max <= gnl->nread + gnl->cur + 1)
		gnl->max <<= 1;
	tmp = malloc(gnl->max + 1);
	if (!tmp)
	{
		free(gnl->l);
		return (0);
	}
	i = -1;
	while (++i < gnl->cur)
		tmp[i] = gnl->l[i];
	free(gnl->l);
	gnl->l = tmp;
	return (1);
}

static void	handle_rest(t_gnl *gnl, t_rest *rest, size_t i)
{
	if (i < (size_t)gnl->nread)
	{
		rest->len = gnl->nread - i;
		rest->i += i;
	}
	else
	{
		rest->len = 0;
		rest->i = 0;
	}
}

static bool	btol(t_gnl *gnl, t_rest *rest)
{
	bool	f_nl;
	size_t	i;

	f_nl = 0;
	i = 0;
	while (!f_nl && i < (size_t)gnl->nread)
	{
		gnl->l[gnl->cur++] = rest->b[rest->i + i];
		if (rest->b[rest->i + i++] == '\n')
		{
			gnl->cur--;
			f_nl = 1;
		}
	}
	handle_rest(gnl, rest, i);
	gnl->l[gnl->cur] = 0;
	gnl->nread = 0;
	return (f_nl);
}

extern t_errcode	get_next_line_no_nl(int fd, char **s)
{
	static t_rest	rest = {0};
	t_gnl			gnl;

	prep(&gnl, &rest);
	while (1)
	{
		if (gnl.nread && gnl.max <= gnl.cur + gnl.nread + 1 && !alloc_l(&gnl))
			return (MALLOC_ERR);
		if (gnl.nread && btol(&gnl, &rest))
			break ;
		gnl.nread = read(fd, rest.b, BUFFER_SIZE);
		if (gnl.nread < 1)
			break ;
	}
	if ((!gnl.cur && !gnl.nread) || gnl.nread < 0)
	{
		free(gnl.l);
		gnl.l = NULL;
	}
	*s = gnl.l;
	return (NO_ERR);
}
