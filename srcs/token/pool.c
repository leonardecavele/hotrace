/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 11:02:22 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 11:58:55 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "helpers.h"

extern t_token	*token_pool_new(t_token_block **last)
{
	t_token_block	*b;

	if (!last)
		return (NULL);
	b = *last;
	if (!b || b->used >= TOKEN_BLOCK_CAP)
	{
		b = (t_token_block *)malloc(sizeof(t_token_block));
		if (!b)
			return (NULL);
		b->used = 0;
		b->next = *last;
		*last = b;
	}
	return (&b->items[b->used++]);
}

extern void	token_pool_destroy(t_token_block **last)
{
	t_token_block	*cur;
	t_token_block	*nxt;

	if (!last)
		return ;
	cur = *last;
	while (cur)
	{
		nxt = cur->next;
		free(cur);
		cur = nxt;
	}
	*last = NULL;
}
