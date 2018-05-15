/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapped_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:53:12 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:53:38 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
