/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:55:24 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 18:11:55 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			format_str(const char *format, t_info *info)
{
	int		count;

	count = 0;
	info->i++;
	if (!format[info->i])
		return (0);
	if (!add_flags(format, info))
		return (-1);
	if ((count = put_specifier(format, info)) < 0)
		return (-1);
	return (count);
}

void		reset_info(t_info *info)
{
	info->flags = 0;
	info->prec = -1;
	info->min_field_width = 0;
	info->length[0] = 0;
	info->length[1] = 0;
}

static void	not_percent(const char *format, t_info *info, int *count)
{
	ft_putchar(format[info->i]);
	(*count)++;
	info->i++;
}

static void	free_info(t_info *info)
{
	va_end(info->ap);
	free(info);
}

int			ft_printf(const char *format, ...)
{
	t_info	*info;
	int		count;
	int		ret;

	info = (t_info *)malloc(sizeof(t_info));
	info->i = 0;
	va_start(info->ap, format);
	count = 0;
	while (format[info->i])
	{
		reset_info(info);
		if (format[info->i] == '%')
		{
			if ((ret = format_str(format, info)) < 0)
			{
				free_info(info);
				return (-1);
			}
			count += ret;
		}
		else
			not_percent(format, info, &count);
	}
	free_info(info);
	return (count);
}
