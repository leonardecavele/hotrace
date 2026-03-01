/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:26 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 11:58:24 by ldecavel         ###   ########.fr       */
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

extern bool	get_token_value(t_token *table[HASH_SIZE], char *key, char **value)
{
	size_t	h;
	size_t	index;
	t_token	*root;

	h = hash_fnv1a(key);
	index = h & (HASH_SIZE - 1);
	root = table[index];
	while (root)
	{
		if (root->hash == h && !ft_strcmp(root->key, key))
		{
			*value = root->value;
			return (true);
		}
		root = root->next;
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
	size_t	h;
	size_t	index;
	t_token	*root;
	t_token	*tok;

	h = hash_fnv1a(key);
	index = h & (HASH_SIZE - 1);
	root = table[index];
	while (root)
	{
		if (root->hash == h && !ft_strcmp(root->key, key))
		{
			free(key);
			if (root->value)
				free(root->value);
			root->value = value;
			return (NO_ERR);
		}
		root = root->next;
	}
	tok = token_pool_new(last);
	if (!tok)
		return (free_key_value(&key, &value, MALLOC_ERR));
	*tok = (t_token){0};
	tok->hash = h;
	tok->key = key;
	tok->value = value;
	list_push_back(&table[index], tok);
	return (NO_ERR);
}
