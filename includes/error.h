/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:03:56 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 16:26:14 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef int	t_errcode;

typedef enum e_errors {
	NO_ERR,
	MALLOC_ERR,
	DICTIONARY_ERR,
}	t_errors;

#endif
