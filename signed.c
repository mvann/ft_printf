/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:42:05 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:09:32 by mvann            ###   ########.fr       */
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
		return ((long)va_arg(info->ap, size_t)); //might need signed size_t here
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
	s = ft_ltoa_base(n, 10, is_flagged(info->flags, FLAGS, '+'), is_flagged(info->flags, FLAGS, ' '));
	if (s[0] == '0' && info->precision == 0)
	{
		free(s);
		return (putnchars(' ', info->min_field_width));
	}
	return (print_number(info, 10, 0, s));

}

int	print_number(t_info *info, int base, int uppercase, char *s)
{
	int e;
	int i;
	int s_len;
	int	precision;
	int	count;

	// printf("s:%s\n", s);
	s_len = ft_strlen(s) + (is_flagged(info->flags, FLAGS, '#') && base == 16 ?
		2 : 0);
	s_len += (is_flagged(info->flags, FLAGS, '#') && base == 8 ? 1 : 0);
	s_len = s[0] == '0' ? 1 : s_len;
	precision = info->precision < 0 ? 1 : info->precision;
	precision = precision - (s_len) + (s[0] == '-' || s[0] == '+' || s[0] == ' ');
	e = info->min_field_width - (s_len + (precision >= 0 ? precision : 0) + ((base == -1) * 2));
	count = 0;
	if ((!is_flagged(info->flags, FLAGS, '0') ||
	(is_flagged(info->flags, FLAGS, '0') && info->precision >= 0)) &&
	!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', e);
	if (base == 16 && is_flagged(info->flags, FLAGS, '#') && s[0] != '0')
		count += put_str_retlen(uppercase ? "0X" : "0x");
	else if (base == 8 && is_flagged(info->flags, FLAGS, '#') && s[0] != '0')
		count += put_str_retlen("0");
	else if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
		count += putnchars(s[0], 1);
	else if (base == -1)
		count += put_str_retlen("0x");
	if ((is_flagged(info->flags, FLAGS, '0') && info->precision < 0) && !is_flagged(info->flags, FLAGS, '-'))
		count += putnchars('0', e);
	count += putnchars('0', precision + (is_flagged(info->flags, FLAGS, '#') && base == 16 && info->precision >= 0 ?
		2 : 0));
	i = (s[0] == '-' || s[0] == '+' || s[0] == ' ');
	while (s[i])
	{
		ft_putchar(s[i++]);
		count++;
	}
	free(s);
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', e);
	return (count);
}
