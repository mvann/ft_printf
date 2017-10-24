/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:55:24 by mvann             #+#    #+#             */
/*   Updated: 2017/10/23 14:46:35 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //DELETE ME #######################

// void	init_func_arr(functiontype (*func_arr)[FUNC_ARR_SIZE])
// {
// 	(*func_arr)['d'] = &ft_itod;
// }
//
// void	(*func_arr[FUNC_ARR_SIZE]);

void	print_info(t_info *info)
{
	printf("\ni:%i\n", info->i);
	printf("flags:%i\n", info->flags);
	printf("precision:%i\n", info->precision);
	printf("min_field_width:%i\n", info->min_field_width);
	printf("l0:%c, l1: %c\n\n", info->length[0], info->length[1]);
}

int		ft_str_iofc(char *str, char c)
{
	char *ptr;

	// ptr = NULL;
	if ((ptr = ft_strchr(str, c)))
		return ((int)(ptr - str));
	return (-1);
}

int		format_str(const char *format, t_info *info)
{
	// char	c;
	int		count;

	count = 0;
	info->i++;
	if (format[info->i] == '%')
	{
		ft_putchar('%');
		info->i++;
		return (1);
	}
	if (!add_flags(format, info))
		return (-1);
	if ((count = put_specifier(format, info)) < 0)
		return (-1);
	return (count);
}

void	reset_info(t_info *info)
{
	info->flags = 0;
	info->precision = 1;
	info->min_field_width = 0;
	info->length[0] = 0;
	info->length[1] = 0;
}

int		ft_printf(const char *format, ...)
{
	t_info	*info;
	int		count;
	int		ret;

	info = (t_info *)malloc(sizeof(t_info));
	reset_info(info);
	info->i = 0;
	va_start(info->ap, format);
	count = 0;
	while (format[info->i])
	{
		if (format[info->i] == '%')
		{
			if ((ret = format_str(format, info)) < 0)
				return (-1);
			// print_info(info);
			count += ret;
		}
		else
		{
			ft_putchar(format[info->i]);
			count++;
			info->i++;
		}
	}

	va_end(info->ap);
	free(info);
	return (count);
}
