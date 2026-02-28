/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:34:51 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 15:27:01 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

extern int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && (uint8_t)s1[i] == (uint8_t)s2[i])
		i++;
	return ((uint8_t)s1[i] - (uint8_t)s2[i]);
}
