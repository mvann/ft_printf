/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:03 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:44:54 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_long_helper(t_info *info, int *count, wchar_t *s)
{
	int	i;
	int ret;

	i = 0;
	while (s[i] && (i < info->prec || info->prec < 0))
	{
		if ((ret = print_char(info->length, s[i])) < 0)
			return (-1);
		(*count)++;
		i++;
	}
	return (1);
}

static int	print_s_helper(t_info *info, int *count, char *s)
{
	int	i;
	int ret;

	i = 0;
	while (s[i] && (i < info->prec || info->prec < 0))
	{
		if ((ret = print_char(info->length, (char)s[i])) < 0)
			return (-1);
		(*count) += ret;
		i++;
	}
	return (1);
}

int			print_long_s(t_info *info)
{
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
	lesser = info->prec < len && info->prec >= 0 ? info->prec : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	if ((ret = print_long_helper(info, &count, s)) < 0)
		return (-1);
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
	lesser = info->prec < len && info->prec >= 0 ? info->prec : len;
	if (!is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	if ((ret = print_s_helper(info, &count, s)) < 0)
		return (-1);
	if (is_flagged(info->flags, FLAGS, '-'))
		count += putnchars(' ', info->min_field_width - lesser);
	return (count);
}
