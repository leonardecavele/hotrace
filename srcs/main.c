/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 20:11:48 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "token.h"
#include "helpers.h"

static t_errcode	parse_dictionary(t_token *table[HASH_SIZE])
{
	t_errcode	errcode_gnl;
	t_errcode	errcode_token;
	char		*key;
	char		*value;

	key = NULL;
	value = NULL;
	errcode_gnl = get_next_line_no_nl(0, &key);
	if (!key)
		return (errcode_gnl);
	errcode_gnl |= get_next_line_no_nl(0, &value);
	while (key && errcode_gnl == NO_ERR)
	{
		errcode_token = create_token(table, key, value);
		if (errcode_token != NO_ERR)
			return (free_all_tokens_errcode(table, errcode_token));
		errcode_gnl = get_next_line_no_nl(0, &key);
		if (!key)
			return (errcode_gnl);
		errcode_gnl |= get_next_line_no_nl(0, &value);
	}
	return (errcode_gnl);
}

static t_errcode	parse_input(t_token *table[HASH_SIZE])
{
	t_errcode	errcode_gnl;
	char		*key;
	char		*value;

	key = NULL;
	errcode_gnl = get_next_line_no_nl(0, &key);
	while (errcode_gnl == NO_ERR && key)
	{
		if (!get_token_value(table, key, &value))
		{
			ft_putstr_fd(2, key);
			ft_putstr_fd(2, ": Not found.\n");
		}
		else
		{
			ft_putstr_fd(1, value);
			ft_putstr_fd(1, "\n");
		}
		free(key);
		errcode_gnl = get_next_line_no_nl(0, &key);
	}
	free(key);
	return (errcode_gnl);
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
