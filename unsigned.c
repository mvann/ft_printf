/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:43:18 by mvann             #+#    #+#             */
/*   Updated: 2017/11/15 18:38:13 by mvann            ###   ########.fr       */
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
			return ((long)va_arg(info->ap, unsigned int));
		else
			return ((long)va_arg(info->ap, unsigned int));
	}
	else if (l[0] == 'j')
		return ((long)va_arg(info->ap, uintmax_t));
	else if (l[0] == 'z')
		return ((long)va_arg(info->ap, size_t));
	return ((long)va_arg(info->ap, unsigned int));
}

int				print_unsigned(t_info *info, int base, int uppercase)
{
	unsigned long n;
	char *s;
	// int i;
	// int e;
	int count;

	n = get_unsigned(info->length, info);
	s = ft_ultoa_base(n, base, uppercase);
	// i = 0;
	// e = info->min_field_width - ft_strlen(s);
	count = 0;

	if (s[0] == '0' && info->precision == 0)
	{
		free(s);
		if (is_flagged(info->flags, FLAGS, '#') && base == 8)
			count += put_str_retlen("0");
		return (count + putnchars(' ', info->min_field_width -
			(base == 8 && is_flagged(info->flags, FLAGS, '#'))));
	}
	return (print_number(info, base, uppercase, s));
}
