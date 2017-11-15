/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:01:08 by mvann             #+#    #+#             */
/*   Updated: 2017/11/13 21:01:49 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_instr(char *str, char c)
{
	return (ft_str_iofc(str, c) != -1);
}

int		is_flagged(int flags, char *str, char c)
{
	return (flags & (1 << ft_str_iofc(str, c)));
}

void	add_flag(t_info *info, char *str, char c)
{
	info->flags |= (1 << ft_str_iofc(str, c));
}
