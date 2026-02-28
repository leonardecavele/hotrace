/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:26 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 16:28:49 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "helpers.h"

extern t_errcode	free_all_tokens_errcode(t_token *table[HASH_SIZE], int errcode)
{
	free_all_tokens(table);
	return (errcode);
}

extern void	free_all_tokens(t_token *table[HASH_SIZE])
{
	size_t	i;

	i = -1;
	while (++i < HASH_SIZE)
		list_clear(&table[i]);
}

extern char	*get_token_value(t_token *table[HASH_SIZE], char *key)
{
	size_t	index;
	t_token	*root;

	index = hash_fnv1a(key) & (HASH_SIZE - 1);
	root = table[index];
	while (root)
	{
		if (!ft_strcmp(root->key, key))
			return (root->value);
		root = root->next;
	}
	return (NULL);
}

extern t_errcode	create_token(t_token *table[HASH_SIZE], char *key, char *value)
{
	size_t		index;

	index = hash_fnv1a(key) & (HASH_SIZE - 1);
	return (list_push_back_new(&table[index], key, value));
}
