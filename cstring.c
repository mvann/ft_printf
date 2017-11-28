/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:03 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:26:47 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_long_s(t_info *info)
{
	int		i;
	int		len;
	int		count;
	int		ret;
	int		lesser;
	wchar_t	*s;

	s = va_arg(info->ap, wchar_t *);
	if (!s)
	{
		info->length[0] = ' ';
		info->length[1] = ' ';
		s = L"(null)";
	}
	count = 0;
	len = 0;
	while (s[len])
		len++;
	lesser = info->precision < len && info->precision >= 0 ? info->precision : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	i = 0;
	while (s[i] && (i < info->precision || info->precision < 0))
	{
		if ((ret = print_char(info->length, s[i])) < 0)
			return (-1);
		count++;
		i++;
	}
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	return (count);
}

int			print_s(t_info *info)
{
	char	*s;
	int		count;
	int		len;
	int		lesser;
	int		i;
	int		ret;

	if (info->length[0] == 'l' && info->length[1] != 'l')
		return (print_long_s(info));
	s = va_arg(info->ap, char *);
	if (!s)
	{
		info->length[0] = ' ';
		info->length[1] = ' ';
		s = "(null)";
	}
	count = 0;
	len = ft_strlen(s);
	lesser = info->precision < len && info->precision >= 0 ? info->precision : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	i = 0;
	while (s[i] && (i < info->precision || info->precision < 0))
	{
		if ((ret = print_char(info->length, (char)s[i])) < 0)
			return (-1);
		count += ret;
		i++;
	}
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	return (count);
}

// int			wstrlen(wchar_t *s)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*narrow;
//
// 	len = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		j = 0;
// 		narrow = (char *)(s + i);
// 		while (j < sizeof(wchar_t))
// 		{
// 			if (narrow[j])
// 				len++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (len);
// }
