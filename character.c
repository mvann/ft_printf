/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:21:28 by mvann             #+#    #+#             */
/*   Updated: 2017/10/24 13:56:42 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char length[2], int c)
{
	if (length[0] != 'l')
		write(1, &c, 1);
	else
		ft_putwchar(c);
	return (1);
}

int		print_c(t_info *info)
{
	char c;
	int		i;
	int		count;

	count = 0;
	c = va_arg(info->ap, int);
	while (count < info->min_field_width)
	{
		if (is_flagged(info->flags, FLAGS, '-'))
		{
			if (count == 0)
				count += print_char(c);
			else
				count += print_char(is_flagged(info->flags, FLAGS, '0') ? '0' : ' ');
		}
		else
		{
			if (count == info->min_field_width - 1)
				count += print_char(c);
			else
				count += print_char(is_flagged(info->flags, FLAGS, '0') ? '0' : ' ');
		}
	}
	ft_putwchar(c);
	return (1);
}
