/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:19:26 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 01:29:14 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "helpers.h"

extern t_errcode	free_all_tokens_errcode(
	t_token *table[HASH_SIZE],
	int errcode
)
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

extern bool	get_token_value(t_token *table[HASH_SIZE], char *key, char **value)
{
	size_t	index;
	t_token	*root;
	char	*null_value;

	null_value = "<(null)>";
	index = hash_fnv1a(key) & (HASH_SIZE - 1);
	root = table[index];
	while (root)
	{
		if (!ft_strcmp(root->key, key))
		{
			*value = root->value;
			if (!*value)
				*value = null_value;
			return (true);
		}
		root = root->next;
	}
	*value = NULL;
	return (false);
}

static bool	token_collision(
	t_token *table[HASH_SIZE],
	char *key,
	char *value,
	size_t index
)
{
	t_token	*root;

	root = table[index];
	while (root)
	{
		if (!ft_strcmp(root->key, key))
		{
			free(key);
			free(root->value);
			root->value = value;
			return (true);
		}
		root = root->next;
	}
	return (false);
}

extern t_errcode	create_token(
	t_token *table[HASH_SIZE],
	char **key,
	char **value
)
{
	size_t		index;
	t_errcode	errcode;

	index = hash_fnv1a(*key) & (HASH_SIZE - 1);
	if (token_collision(table, *key, *value, index))
	{
		*key = NULL;
		*value = NULL;
		return (NO_ERR);
	}
	errcode = list_push_back_new(&table[index], *key, *value);
	if (errcode != NO_ERR)
	{
		free(*key);
		free(*value);
	}
	*key = NULL;
	*value = NULL;
	return (errcode);
}
