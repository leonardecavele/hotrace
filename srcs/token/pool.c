/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 11:02:22 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:15:44 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "helpers.h"

extern t_token	*token_pool_new(t_token_block **last)
{
	t_token_block	*block;

	if (!last)
		return (NULL);
	block = *last;
	if (!block || block->used >= TOKEN_BLOCK_CAP)
	{
		block = (t_token_block *)malloc(sizeof(t_token_block));
		if (!block)
			return (NULL);
		*block = (t_token_block){.next = *last};
		*last = block;
	}
	return (&block->items[block->used++]);
}

extern void	token_pool_destroy(t_token_block **last)
{
	t_token_block	*current;
	t_token_block	*next;

	if (!last)
		return ;
	current = *last;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*last = NULL;
}
