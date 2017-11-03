/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:57:48 by mvann             #+#    #+#             */
/*   Updated: 2017/10/24 14:04:31 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void init_funcs(t_specifier_func *funcs)
{
	funcs[0] = NULL;
	funcs[1] = NULL;
	funcs[2] = NULL;
	funcs[3] = NULL;
	funcs[4] = NULL;
	funcs[5] = NULL;
	funcs[6] = NULL;
	funcs[7] = NULL;
	funcs[8] = NULL;
	funcs[9] = NULL;
	funcs[10] = NULL;
	funcs[11] = NULL;
	funcs[12] = &print_c;
	funcs[13] = NULL;
}

int		put_specifier(const char *format, t_info *info)
{
	char c;

	t_specifier_func *funcs;

	c = format[info->i];
	if (!is_instr(SPECIFIERS, c))
		return (-1);
	funcs = (t_specifier_func *)malloc(
		sizeof(t_specifier_func) * ft_strlen(SPECIFIERS));
	init_funcs(funcs);
	(*funcs[ft_str_iofc(SPECIFIERS, c)])(info);
	info->i++;
	return (0);
}
