/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 16:58:23 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "token.h"
#include "helpers.h"

static t_errcode	parse_dictionary(t_token *table[HASH_SIZE])
{
	t_errcode	errcode;
	char		*key;
	char		*value;

	key = NULL;
	value = NULL;
	// if malloc fail in gnl, silent error
	// need to get without the \n
	while (get_next_line_no_nl(0, &key) && get_next_line_no_nl(0, &value))
	{
		__builtin_printf("<%s> <%s>\n", key, value);
		if (!key && !value)
			break ;
		if (!key || !value)
			return (free_all_tokens_errcode(table, DICTIONARY_ERR));
		errcode = create_token(table, key, value);
		if (errcode != NO_ERR)
			return (free_all_tokens_errcode(table, errcode));
	}
	return (NO_ERR);
}

static t_errcode	parse_input(t_token *table[HASH_SIZE])
{
	char	*key;
	char	*value;

	key = NULL;
	// if malloc fail in gnl, silent error
	while (get_next_line_no_nl(0, &key))
	{
		if (!key)
			break ;
		value = get_token_value(table, key);
		if (!value)
		{
			ft_putstr_fd(2, key);
			ft_putstr_fd(2, ": Not found.\n");
		}
		else
		{
			ft_putstr_fd(1, value);
			ft_putstr_fd(1, "\n");
		}
	}
	return (NO_ERR);
}

t_errcode	main(void)
{
	t_errcode		errcode;
	static t_token	*table[HASH_SIZE] = {0};

	errcode = parse_dictionary(table);
	if (errcode != NO_ERR)
		return (errcode);
	errcode = parse_input(table);
	if (errcode != NO_ERR)
		return (errcode);
	free_all_tokens(table);
	return (NO_ERR);
}
