/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:21:28 by mvann             #+#    #+#             */
/*   Updated: 2017/11/14 20:20:42 by mvann            ###   ########.fr       */
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
	int		c;
	int		count;
	int		c_index;

	count = 0;
	c = va_arg(info->ap, int);
	c_index = (is_flagged(info->flags, FLAGS, '-')
		? info->min_field_width - 1 : 0);
	while (count < info->min_field_width || count < 1)
	{
		if (count == c_index)
			count += print_char(info->length, c);
		else
			count += print_char("  ",
			is_flagged(info->flags, FLAGS, '0') ? '0' : ' ');
	}
	// ft_putwchar(c);
	return (1);
}

int		print_percentage(t_info *info)
{
	int		c;
	int		count;
	int		c_index;

	count = 0;
	c = '%';
	c_index = (is_flagged(info->flags, FLAGS, '-')
		? info->min_field_width - 1 : 0);
	while (count < info->min_field_width || count < 1)
	{
		if (count == c_index)
			count += print_char(info->length, c);
		else
			count += print_char("  ",
			is_flagged(info->flags, FLAGS, '0') ? '0' : ' ');
	}
	//ft_putwchar(c);
	return (1);
}
