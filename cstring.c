/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:03 by mvann             #+#    #+#             */
/*   Updated: 2017/11/20 12:55:26 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	print_s_chars(char *s)
// {
// 	int i;
// 	int count;
//
// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		if ((unsigned char)(s[i]) >= 192 || (unsigned char)(s[i]) < 128)
// 		{
// 			ft_putwchar((int)s[i]);
// 			// count++;
// 		}
// 		// ft_putchar(s[i]);
// 		count++;
// 		i++;
// 	}
// 	return (count);
// }

int			print_long_s(t_info *info)
{
	int		len;
	int		count;
	int		ret;
	int		lesser;
	wchar_t	*s;

	s = va_arg(info->ap, wchar_t *);;
	count = 0;
	len = 0;
	while (s[len])
		len++;
	lesser = info->precision < len && info->precision >= 0 ? info->precision : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	while (*s)
	{
		if ((ret = print_char(info->length, *s)) < 0)
			return (-1);
		count++;
		s++;
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

	s = va_arg(info->ap, char *);
	if (!s)
	{
		info->length[0] = ' ';
		info->length[1] = ' ';
		s = "(null)";
	}
	if (info->length[0] == 'l' && info->length[1] != 'l')
		return (print_long_s(info));
	count = 0;
	len = ft_strlen(s);//(info->length[0] == 'l' && info->length[1] != 'l') ?
		// wstrlen((wchar_t *)s) : ft_strlen(s);
	lesser = info->precision < len && info->precision >= 0 ? info->precision : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	i = 0;
	while (s[i])
	{
		if ((ret = print_char(info->length, s[i])) < 0)
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
