/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:31:51 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 17:27:11 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

extern void	list_clear(t_token **root)
{
	t_token	*current;
	t_token	*next;

	if (!root || !*root)
		return ;
	current = *root;
	while (current)
	{
		next = (*root)->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	*root = NULL;
}

extern void	list_push_back(t_token **root, t_token *token)
{
	t_token	*last;

	if (!root || !token)
		return ;
	if (!*root)
	{
		*root = token;
		token->prev = token;
		return ;
	}
	last = (*root)->prev;
	token->prev = last;
	last->next = token;
	(*root)->prev = token;
	return ;
}

extern t_errcode	list_push_back_new(t_token **root, char *key, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (MALLOC_ERR);
	token->key = key;
	token->value = value;
	token->next = NULL;
	token->prev = NULL;
	list_push_back(root, token);
	return (NO_ERR);
}
