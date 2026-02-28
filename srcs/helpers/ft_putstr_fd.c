/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:26:40 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 16:13:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

extern void	ft_putstr_fd(int fd, const char *s)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
