/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:43:18 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 17:48:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	get_unsigned(char l[2], t_info *info)
{
	if (l[0] == 'l')
	{
		if (l[1] == 'l')
			return (va_arg(info->ap, unsigned long));
		else
			return (va_arg(info->ap, unsigned long));
	}
	else if (l[0] == 'h')
	{
		if (l[1] == 'h')
			return ((long)(char)va_arg(info->ap, unsigned int));
		else
			return ((long)(short)va_arg(info->ap, unsigned int));
	}
	else if (l[0] == 'j')
		return ((long)va_arg(info->ap, uintmax_t));
	else if (l[0] == 'z')
		return ((long)va_arg(info->ap, size_t));
	return ((long)va_arg(info->ap, unsigned int));
}

static void		get_n(t_info *info, unsigned long *n)
{
	*n = get_unsigned(info->length, info);
	if (info->length[0] == 'h')
	{
		if (info->length[1] == 'h')
			(*n) = (*n) & 0x00000000000000FF;
		else
			(*n) = (*n) & 0x000000000000FFFF;
	}
}

int				print_unsigned(t_info *info, int base, int uppercase)
{
	unsigned long	n;
	char			*s;
	int				count;
	int				octal_and_hash;

	get_n(info, &n);
	s = ft_ultoa_base(n, base, uppercase);
	count = 0;
	octal_and_hash = base == 8 && is_flagged(info->flags, FLAGS, '#');
	if (s[0] == '0' && info->prec == 0)
	{
		free(s);
		if (!is_flagged(info->flags, FLAGS, '-'))
			count += putnchars(' ', info->min_field_width - octal_and_hash);
		if (octal_and_hash)
			count += put_str_retlen("0");
		if (is_flagged(info->flags, FLAGS, '-'))
			count += putnchars(' ', info->min_field_width - octal_and_hash);
		return (count);
	}
	return (print_number(info, base, uppercase, s));
}

int				print_pointer(t_info *info)
{
	unsigned long	n;
	char			*s;
	int				count;

	add_flag(info, FLAGS, '#');
	n = va_arg(info->ap, unsigned long);
	s = ft_ultoa_base(n, 16, 0);
	count = 0;
	if (s[0] == '0' && info->prec == 0)
	{
		free(s);
		if (!is_flagged(info->flags, FLAGS, '-'))
			count += putnchars(' ', info->min_field_width - 2);
		count += put_str_retlen("0x");
		if (is_flagged(info->flags, FLAGS, '-'))
			count += putnchars(' ', info->min_field_width - 2);
		return (count);
	}
	return (print_number(info, -1, 0, s));
}
