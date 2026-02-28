/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:34:51 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 12:37:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

extern int	free_all_tokens_errcode(int errcode)
{
	free_all_tokens();
	return (errcode);
}
