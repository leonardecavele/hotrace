/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:31:51 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 10:45:56 by ldecavel         ###   ########.fr       */
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
		next = current->next;
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		current->key = NULL;
		current->value = NULL;
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
}
