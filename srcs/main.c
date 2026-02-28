/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 13:20:34 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error.h"
#include "token.h"
#include "get_next_line.h"

static int	parse_dictionary(t_token *table[HASH_SIZE])
{
	int		errcode;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	// if malloc fail in gnl, silent error
	while (get_next_line(0, &key) && get_next_line(0, &value))
	{
		if (!key || !value)
			return (free_all_tokens_errcode(&table, DICTIONARY_ERR))
		errcode = create_token(&table, key, value);
		if (errcode != NO_ERR)
			return (free_all_tokens_errcode(&table, errcode))
	}

	return (NO_ERR);
}

static int	parse_input(t_token *table[HASH_SIZE])
{
	char	*key;
	char	*value;

	key = NULL;
	// if malloc fail in gnl, silent error
	while (get_next_line(0, &key))
	{
		value = get_token_value(table, key);
		// if NULL (not found)

		// display value
		__builtin_printf("%s\n", value); 
	}

	return (NO_ERR);
}

int	main(void)
{
	int				errcode;
	static t_token	*table[HASH_SIZE] = {0};

	errcode = parse_dictionary(table);
	if (errcode != NO_ERR)
		return (errcode);

	errcode = parse_input(table);
	if (errcode != NO_ERR)
		return (errcode);

	return (NO_ERR);
}
