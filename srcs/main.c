/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 01:31:26 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "token.h"
#include "helpers.h"

static t_errcode	free_key_value(char **key, char **value, t_errcode errcode)
{
	if (key && *key)
	{
		free(*key);
		*key = NULL;
	}
	if (value && *value)
	{
		free(*value);
		*value = NULL;
	}
	return (errcode);
}

static t_errcode	parse_dictionary(t_token *table[HASH_SIZE])
{
	t_errcode	err;
	char		*key;
	char		*value;

	key = NULL;
	value = NULL;
	while (1)
	{
		err = get_next_line_no_nl(0, &key);
		if (err != NO_ERR)
			return (free_key_value(&key, &value, err));
		if (!key || !*key)
			return (free_key_value(&key, &value, NO_ERR));
		err = get_next_line_no_nl(0, &value);
		if (err != NO_ERR)
			return (free_key_value(&key, &value, err));
		if (!value)
			return (free_key_value(&key, &value, DICTIONARY_ERR));
		err = create_token(table, &key, &value);
		if (err != NO_ERR)
			return (free_key_value(&key, &value, err));
		key = NULL;
		value = NULL;
	}
}

static t_errcode	parse_input(t_token *table[HASH_SIZE])
{
	t_errcode	err;
	char		*key;
	char		*value;

	key = NULL;
	while (1)
	{
		err = get_next_line_no_nl(0, &key);
		if (err != NO_ERR)
			return (free_key_value(&key, NULL, err));
		if (!key || !*key)
			return (free_key_value(&key, NULL, NO_ERR));
		if (get_token_value(table, key, &value))
			ft_putstr_fd(1, value);
		else
		{
			ft_putstr_fd(1, key);
			ft_putstr_fd(1, ": Not found.");
		}
		ft_putstr_fd(1, "\n");
		free_key_value(&key, NULL, NO_ERR);
	}
}

int	main(void)
{
	t_errcode		errcode;
	static t_token	*table[HASH_SIZE] = {0};

	errcode = parse_dictionary(table);
	if (errcode != NO_ERR)
	{
		free_all_tokens(table);
		return (errcode);
	}
	errcode = parse_input(table);
	if (errcode != NO_ERR)
	{
		free_all_tokens(table);
		return (errcode);
	}
	free_all_tokens(table);
	return (errcode);
}
