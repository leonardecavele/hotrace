/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:27:10 by ldecavel          #+#    #+#             */
/*   Updated: 2026/02/28 20:11:12 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <sys/stat.h>
#include <stdint.h>

#ifndef __x86_64__
# error "This inline asm version is for x86_64 only."
#endif

#ifndef __NR_FSTAT
# define __NR_FSTAT 5
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

	if (sys_fstat(0, &st) != 0)
		return (false);
	if (S_ISCHR(st.st_mode))
		return (true);
	return (false);
}
