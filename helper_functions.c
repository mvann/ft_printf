/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:40:08 by mvann             #+#    #+#             */
/*   Updated: 2017/11/14 15:41:50 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putnchars(char c, int n)
{
	int count;

	count = n > 0 ? n : 0;
	while (n-- > 0)
		ft_putchar(c);
	return (count);
}

int		ft_str_iofc(char *str, char c)
{
	char *ptr;

	if ((ptr = ft_strchr(str, c)))
		return ((int)(ptr - str));
	return (-1);
}
