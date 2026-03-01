/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:26:40 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 16:13:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

extern size_t	ft_size_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

extern size_t	ft_size_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
