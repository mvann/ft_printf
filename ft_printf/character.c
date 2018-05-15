/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:21:28 by mvann             #+#    #+#             */
/*   Updated: 2017/11/20 13:02:27 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char length[2], int c)
{
	if (length[0] == 'l' && length[1] != 'l')
	{
		if ((unsigned int)c > 255)
			return (-1);
	}
	ft_putchar(c);
	return (1);
}

int		print_c(t_info *info, int use_percentage)
{
	int		c;
	int		count;
	int		c_index;
	int		ret;

	count = 0;
	c = use_percentage ? '%' : va_arg(info->ap, int);
	c_index = (is_flagged(info->flags, FLAGS, '-')
		? 0 : info->min_field_width - 1);
	while (count < info->min_field_width || count < 1)
	{
		if (count == c_index || info->min_field_width == 0)
		{
			if ((ret = print_char(info->length, c)) < 0)
				return (-1);
			count += ret;
		}
		else
			count += print_char("  ",
				is_flagged(info->flags, FLAGS, '0') ? '0' : ' ');
	}
	return (count);
}

int		print_percentage(t_info *info)
{
	return (print_c(info, 1));
}

int		print_character(t_info *info)
{
	return (print_c(info, 0));
}
