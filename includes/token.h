/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:16:38 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 11:50:29 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdlib.h>
# include <stdbool.h>

# include "error.h"

# define HASH_SIZE			131072

typedef struct s_token
{
	size_t			hash;
	char			*key;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

# define TOKEN_BLOCK_CAP	1024

typedef struct s_token_block
{
	struct s_token_block	*next;
	size_t					used;
	t_token					items[TOKEN_BLOCK_CAP];
}	t_token_block;

/* pool.c */
void		token_pool_init(t_token_block **last);
void		token_pool_destroy(t_token_block **last);
t_token		*token_pool_new(t_token_block **last);
/* token.c */
void		free_all_tokens(t_token *table[HASH_SIZE], t_token_block **last);
bool		get_token_value(t_token *table[HASH_SIZE], char *key, char **value);
t_errcode	create_token(t_token *table[HASH_SIZE], t_token_block **last, char *key, char *value);
t_errcode	free_key_value(char **key, char **value, t_errcode errcode);
/* hash.c */
size_t		hash_fnv1a(const char *s);
/* linked_list.c */
void		list_clear(t_token **root);
void		list_push_back(t_token **root, t_token *token);

#endif
