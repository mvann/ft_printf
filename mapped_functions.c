/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapped_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:14:08 by mvann             #+#    #+#             */
/*   Updated: 2017/11/14 16:14:34 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_oct(t_info *info)
{
	int flagged;

	flagged = is_flagged(info->flags, FLAGS, '#');
	if (flagged)
		ft_putchar('0');
	return (flagged + print_unsigned(info, 8, 0));
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
