/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:27:10 by ldecavel          #+#    #+#             */
/*   Updated: 2026/03/01 20:09:19 by ldecavel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <sys/stat.h>
#include <stdint.h>

#ifndef __NR_FSTAT
# define __NR_FSTAT 5
#endif

#ifdef __x86_64__
# define IS_INTERACTIVE_ENABLED 1
#else
# define IS_INTERACTIVE_ENABLED 0
#endif

static long	sys_fstat(int fd, struct stat *st)
{
	long				ret;
	register long rax	__asm__("rax");
	register long rdi	__asm__("rdi");
	register long rsi	__asm__("rsi");

	rax = __NR_FSTAT;
	rdi = (long)fd;
	rsi = (long)st;
	__asm__ volatile (
		"syscall"
		: "=a"(ret)
		: "a"(rax), "D"(rdi), "S"(rsi)
		: "rcx", "r11", "memory"
	);
	return (ret);
}

bool	stdin_is_interactive(void)
{
	struct stat	st;

	if (!IS_INTERACTIVE_ENABLED)
		return (true);
	if (sys_fstat(0, &st) != 0)
		return (false);
	if (S_ISCHR(st.st_mode))
		return (true);
	return (false);
}
