/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:28:27 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 17:29:10 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_number_helper(t_info *info, int count, int e, char *s)
{
	int i;

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

static int	print_number_helper_2(t_info *info, int e)
{
	int count;

	count = 0;
	if ((!is_flagged(info->flags, FLAGS, '0') ||
	(is_flagged(info->flags, FLAGS, '0') && info->prec >= 0)) &&
	!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', e);
	return (count);
}

static int	print_number_helper_3(t_info *info, char *s, int base, int upper)
{
	int count;

	count = 0;
	if (base == 16 && is_flagged(info->flags, FLAGS, '#') && s[0] != '0')
		count += put_str_retlen(upper ? "0X" : "0x");
	else if (base == 8 && is_flagged(info->flags, FLAGS, '#') && s[0] != '0')
		count += put_str_retlen("0");
	else if (s[0] == '-' || s[0] == '+' || s[0] == ' ')
		count += putnchars(s[0], 1);
	else if (base == -1)
		count += put_str_retlen("0x");
	return (count);
}

int			print_number(t_info *info, int base, int uppercase, char *s)
{
	int e;
	int s_len;
	int	precision;
	int	count;

	s_len = ft_strlen(s) + (is_flagged(info->flags, FLAGS, '#') && base == 16 ?
		2 : 0);
	s_len += (is_flagged(info->flags, FLAGS, '#') && base == 8 ? 1 : 0);
	s_len = s[0] == '0' ? 1 : s_len;
	precision = info->prec < 0 ? 1 : info->prec;
	precision = precision - (s_len) +
		(s[0] == '-' || s[0] == '+' || s[0] == ' ');
	e = info->min_field_width - (s_len + (precision >= 0 ? precision : 0) +
		((base == -1) * 2));
	count = print_number_helper_2(info, e) +
		print_number_helper_3(info, s, base, uppercase);
	if ((is_flagged(info->flags, FLAGS, '0') && info->prec < 0) &&
		!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars('0', e);
	count += putnchars('0', precision + (is_flagged(info->flags, FLAGS, '#') &&
		base == 16 && info->prec >= 0 ? 2 : 0));
	return (print_number_helper(info, count, e, s));
}
