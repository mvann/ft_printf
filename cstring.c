/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:03 by mvann             #+#    #+#             */
/*   Updated: 2017/11/15 16:38:39 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_s_chars(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((unsigned char)(s[i]) >= 192 || (unsigned char)(s[i]) < 128)
		{
			ft_putwchar((int)s[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int			print_s(t_info *info)
{
	char	*s;
	int		count;
	int		len;
	int		lesser;

	s = va_arg(info->ap, char *);
	if (!s)
		s = "(null)";
	count = 0;
	len = ft_strlen(s);
	lesser = info->precision < len && info->precision >= 0 ? info->precision : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	if (info->precision >= 0)
	{
		write(1, s, lesser);
		count += lesser;
	}
	else if (info->length[0] == 'l' && info->length[1] != 'l')
		count += print_s_chars(s);
	else
		count += put_str_retlen(s);
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	return (count);
}
