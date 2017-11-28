/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapped_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:14:08 by mvann             #+#    #+#             */
/*   Updated: 2017/11/20 13:50:55 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_pointer(t_info *info)
// {
// 	info->length[0] = 'l';
// 	info->length[1] = ' ';
// 	add_flag(info, FLAGS, '#');
// 	return (print_unsigned(info, 16, 0));
// }

int	print_capital_s(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_long_s(info));
}

int	print_capital_c(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_character(info));
}

int	print_long_signed_int(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_signed_int(info));
}

int	print_unsigned_oct(t_info *info)
{
	// int flagged;

	// flagged = is_flagged(info->flags, FLAGS, '#');
	// if (flagged)
	// 	ft_putchar('0');
	return (print_unsigned(info, 8, 0));
}

int	print_unsigned_long_oct(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_unsigned(info, 8, 0));
}

int	print_unsigned_hex(t_info *info)
{
	return (print_unsigned(info, 16, 0));
}

int	print_unsigned_hex_upper(t_info *info)
{
	return (print_unsigned(info, 16, 1));
}

int	print_unsigned_int(t_info *info)
{
	return (print_unsigned(info, 10, 0));
}

int	print_long_unsigned_int(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_unsigned(info, 10, 0));
}
