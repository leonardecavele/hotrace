/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:26 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 14:01:30 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

extern void	free_all_tokens(t_token **table[HASH_SIZE])
{
	size_t	i;

	i = -1;
	while (++i < HASH_SIZE)
		list_clear(&table[i]);
}

extern int	free_all_tokens_errcode(t_token **table[HASH_SIZE], int errcode)
{
	free_all_tokens(table);
	return (errcode);
}

extern char	*get_token_value(t_token *table[HASH_SIZE])
{
}

extern int	create_token(t_token **table[HASH_SIZE], char *key, char *value)
{
}
