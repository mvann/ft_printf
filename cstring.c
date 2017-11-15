/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:10:03 by mvann             #+#    #+#             */
/*   Updated: 2017/11/14 17:34:38 by mvann            ###   ########.fr       */
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

	s = va_arg(info->ap, char *);
	if (!s)
		return (-1);
	count = 0;
	len = ft_strlen(s);
	if (info->precision >= 0)
	{
		write(1, s, info->precision < len ? info->precision : len);
		count += info->precision < len ? info->precision : len;
	}
	else if (info->length[0] == 'l' && info->length[1] != 'l')
		count += print_s_chars(s);
	else
	{
		ft_putstr(s);
		count += len;
	}
	return (count);
}
