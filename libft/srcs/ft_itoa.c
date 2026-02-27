/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:37 by ldecavel          #+#    #+#             */
/*   Updated: 2026/01/23 22:18:46 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb <= 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	size_t	size;
	long	nb;
	char	*result;

	nb = n;
	size = get_size(nb);
	result = malloc(size--);
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result[size--] = 0;
	if (nb == 0)
		result[size] = '0';
	while (nb > 0)
	{
		result[size--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
