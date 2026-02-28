/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:16:38 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 17:19:31 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#include <stdlib.h>
#include <stdbool.h>

#include "error.h"

#define HASH_SIZE	4096

typedef struct s_token
{
	char	*key;
	char	*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

/* token.c */
void	free_all_tokens(t_token *table[HASH_SIZE]);
int		free_all_tokens_errcode(t_token *table[HASH_SIZE], int errcode);
bool	get_token_value(t_token *table[HASH_SIZE], char *key, char **value);
int		create_token(t_token *table[HASH_SIZE], char *key, char *value);
/* hash.c */
size_t	hash_fnv1a(const char *s);
/* linked_list.c */
void	list_clear(t_token **root);
void	list_push_back(t_token **root, t_token *token);
int		list_push_back_new(t_token **root, char *key, char *value);

#endif
