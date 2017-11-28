/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:57:48 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 18:21:34 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_funcs(t_specifier_func *funcs)
{
	funcs[0] = &print_s;
	funcs[1] = &print_capital_s;
	funcs[2] = &print_pointer;
	funcs[3] = &print_signed_int;
	funcs[4] = &print_long_signed_int;
	funcs[5] = &print_signed_int;
	funcs[6] = &print_unsigned_oct;
	funcs[7] = &print_unsigned_long_oct;
	funcs[8] = &print_unsigned_int;
	funcs[9] = &print_long_unsigned_int;
	funcs[10] = &print_unsigned_hex;
	funcs[11] = &print_unsigned_hex_upper;
	funcs[12] = &print_character;
	funcs[13] = &print_capital_c;
	funcs[14] = &print_percentage;
}

int		put_specifier(const char *format, t_info *info)
{
	char				c;
	int					count;
	t_specifier_func	*funcs;

	c = format[info->i];
	if (!c || !is_instr(SPECIFIERS, c))
		return (-1);
	funcs = (t_specifier_func *)malloc(
		sizeof(t_specifier_func) * ft_strlen(SPECIFIERS));
	init_funcs(funcs);
	if ((count = (*funcs[ft_str_iofc(SPECIFIERS, c)])(info)) < 0)
	{
		free(funcs);
		return (-1);
	}
	info->i++;
	free(funcs);
	return (count);
}
