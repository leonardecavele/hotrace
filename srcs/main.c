/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:01:39 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "token.h"
#include "helpers.h"

static t_errcode	parse_dictionary(
	t_token *table[HASH_SIZE],
	t_token_block **last
)
{
	t_errcode	errcode;
	char		*key;
	char		*value;

	key = NULL;
	value = NULL;
	while (1)
	{
		errcode = get_next_line_no_nl(0, &key);
		if (errcode != NO_ERR)
			return (free_key_value(&key, &value, errcode));
		if (!key || !*key)
			return (free_key_value(&key, &value, NO_ERR));
		errcode = get_next_line_no_nl(0, &value);
		if (errcode != NO_ERR || !value)
			return (free_key_value(&key, &value, DICTIONARY_ERR));
		errcode = create_token(table, last, key, value);
		key = NULL;
		value = NULL;
		if (errcode != NO_ERR)
			return (errcode);
	}
}

static t_errcode	parse_input(t_token *table[HASH_SIZE])
{
	t_errcode	errcode;
	char		*key;
	char		*value;

	key = NULL;
	while (1)
	{
		errcode = get_next_line_no_nl(0, &key);
		if (errcode != NO_ERR)
			return (free_key_value(&key, NULL, errcode));
		if (!key || !*key)
			return (free_key_value(&key, NULL, NO_ERR));
		if (get_token_value(table, key, &value))
			ft_putstr_fd(1, value);
		else
		{
			ft_putstr_fd(2, key);
			ft_putstr_fd(2, ": Not found.");
		}
		ft_putstr_fd(1, "\n");
		free_key_value(&key, NULL, NO_ERR);
	}
}

int	main(void)
{
	t_errcode		errcode;
	t_token_block	*last;
	static t_token	*table[HASH_SIZE] = {0};

	last = NULL;
	errcode = parse_dictionary(table, &last);
	if (errcode != NO_ERR)
	{
		free_all_tokens(table, &last);
		return (errcode);
	}
	errcode = parse_input(table);
	free_all_tokens(table, &last);
	return (errcode);
}
