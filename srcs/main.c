/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:14:57 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 12:29:21 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "token.h"
#include "helpers.h"
#include "writer.h"

bool	stdin_is_interactive(void);

static inline void	print_not_found(char *key, t_writer *out)
{
	writer_write(out, key, ft_strlen(key));
	writer_write(out, ": Not found.", 12);
}

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

static t_errcode	parse_input(t_token *table[HASH_SIZE], t_writer *out)
{
	t_errcode	errcode;
	char		*key;
	char		*value;
	bool		interactive;

	key = NULL;
	interactive = stdin_is_interactive();
	while (1)
	{
		errcode = get_next_line_no_nl(0, &key);
		if (errcode != NO_ERR)
			return (free_key_value(&key, NULL, errcode));
		if (!key || !*key)
			return (free_key_value(&key, NULL, NO_ERR));
		if (get_token_value(table, key, &value))
			writer_write(out, value, ft_strlen(value));
		else
			print_not_found(key, out);
		writer_write(out, "\n", 1);
		free_key_value(&key, NULL, NO_ERR);
		if (interactive)
			writer_flush(out);
	}
}

int	main(void)
{
	t_errcode		errcode;
	t_token_block	*last;
	char			writer_buf[1024];
	t_writer		writer;
	static t_token	*table[HASH_SIZE] = {0};

	last = NULL;
	writer_init(&writer, STDOUT_FILENO, writer_buf, sizeof(writer_buf));
	errcode = parse_dictionary(table, &last);
	if (errcode != NO_ERR)
	{
		free_all_tokens(table, &last);
		return (errcode);
	}
	errcode = parse_input(table, &writer);
	free_all_tokens(table, &last);
	writer_flush(&writer);
	return (errcode);
}
