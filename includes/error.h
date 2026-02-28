/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:03:56 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 17:31:35 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef int	t_errcode;

typedef enum e_errors
{
	NO_ERR,
	MALLOC_ERR,
	DICTIONARY_ERR,
}	t_errors;

#endif
