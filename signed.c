/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:42:05 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 17:40:58 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	get_decimal(char l[2], t_info *info)
{
	if (l[0] == 'l')
	{
		if (l[1] == 'l')
			return (va_arg(info->ap, long));
		else
			return (va_arg(info->ap, long));
	}
	else if (l[0] == 'h')
	{
		if (l[1] == 'h')
			return ((long)va_arg(info->ap, int));
		else
			return ((long)va_arg(info->ap, int));
	}
	else if (l[0] == 'j')
		return ((long)va_arg(info->ap, intmax_t));
	else if (l[0] == 'z')
		return ((long)va_arg(info->ap, size_t));
	return ((long)va_arg(info->ap, int));
}

int			print_signed_int(t_info *info)
{
	long	n;
	char	*s;

	n = get_decimal(info->length, info);
	if (info->length[0] == 'h')
	{
		if (info->length[1] == 'h')
			n = (long)(char)n;
		else
			n = (long)(short)n;
	}
	s = ft_ltoa_base(n, 10, is_flagged(info->flags, FLAGS, '+'),
		is_flagged(info->flags, FLAGS, ' '));
	if (s[0] == '0' && info->prec == 0)
	{
		free(s);
		return (putnchars(' ', info->min_field_width));
	}
	return (print_number(info, 10, 0, s));
}
