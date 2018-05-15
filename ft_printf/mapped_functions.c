/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapped_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:14:08 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:53:44 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (print_unsigned(info, 8, 0));
}

int	print_unsigned_long_oct(t_info *info)
{
	info->length[0] = 'l';
	info->length[1] = ' ';
	return (print_unsigned(info, 8, 0));
}
