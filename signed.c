/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:42:05 by mvann             #+#    #+#             */
/*   Updated: 2017/11/14 16:11:11 by mvann            ###   ########.fr       */
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
	int		i;
	int		e;
	int		count;

	n = get_decimal(info->length, info);
	s = ft_ltoa_base(n, 10, 0);
	i = 0;
	e = info->precision - ft_strlen(s);
	count = 0;
	if (s[0] == '0' && info->precision == 0)
	{
		free(s);
		return (0);
	}
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(is_flagged(info->flags, FLAGS, '0') ? '0' : ' ', e);
	while (s[i])
	{
		ft_putchar(s[i++]);
		info->precision--;
		count++;
	}
	free(s);
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(is_flagged(info->flags, FLAGS, '0') ? '0' : ' ', e);
	return (count);
}
