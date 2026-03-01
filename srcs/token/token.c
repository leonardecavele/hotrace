/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:26 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:13:41 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "helpers.h"

extern t_errcode	free_key_value(char **key, char **value, t_errcode errcode)
{
	if (key && *key)
	{
		free(*key);
		*key = NULL;
	}
	if (value && *value)
	{
		free(*value);
		*value = NULL;
	}
	return (errcode);
}

extern void	free_all_tokens(t_token *table[HASH_SIZE], t_token_block **last)
{
	size_t	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		list_clear(&table[i]);
		i++;
	}
	token_pool_destroy(last);
}

static t_token	*find_token(t_token *head, size_t hash, const char *key)
{
	while (head && (head->hash != hash || ft_strcmp(head->key, key)))
		head = head->next;
	return (head);
}

extern bool	get_token_value(t_token *table[HASH_SIZE], char *key, char **value)
{
	size_t	hash;
	size_t	index;
	t_token	*token;

	hash = hash_fnv1a(key);
	index = hash & (HASH_SIZE - 1);
	token = token_find(table[index], hash, key);
	if (token != NULL)
	{
		*value = token->value;
		return (true);
	}
	*value = NULL;
	return (false);
}

extern t_errcode	create_token(
	t_token *table[HASH_SIZE],
	t_token_block **last,
	char *key,
	char *value
)
{
	size_t	hash;
	size_t	index;
	t_token	*token;

	hash = hash_fnv1a(key);
	index = hash & (HASH_SIZE - 1);
	token = find_token(table[index], hash, key);
	if (token)
	{
		free(key);
		free(token->value);
		token->value = value;
		return (NO_ERR);
	}
	token = token_pool_new(last);
	if (!token)
		return (free_key_value(&key, &value, MALLOC_ERR));
	*token = (t_token){.hash = hash, .key = key, .value = value};
	list_push_back(&table[index], token);
	return (NO_ERR);
}
