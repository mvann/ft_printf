/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:37:05 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 16:44:20 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_behavior_flags(const char *format, t_info *info)
{
	char c;

	c = format[info->i];
	while (is_instr(BEHAVIOR_FLAGS, c) && c)
	{
		add_flag(info, FLAGS, c);
		info->i++;
		c = format[info->i];
	}
	return (1);
}

int		add_field_width(const char *format, t_info *info)
{
	char c;

	info->min_field_width = 0;
	c = format[info->i];
	if (c == '*')
	{
		info->min_field_width = va_arg(info->ap, int);
		if (info->min_field_width < 0)
		{
			add_flag(info, FLAGS, '-');
			info->min_field_width *= -1;
		}
		info->i++;
	}
	else if (c >= '0' && c <= '9')
	{
		info->min_field_width = ft_atoi(format + info->i);
		while (format[info->i] >= '0' && format[info->i] <= '9'
		&& format[info->i])
			info->i++;
	}
	return (1);
}

int		add_precision(const char *format, t_info *info)
{
	char	c;

	if (format[info->i] != '.')
		return (1);
	info->i++;
	c = format[info->i];
	if (c == '*')
	{
		info->prec = va_arg(info->ap, int);
		info->i++;
	}
	else if (c >= '0' && c <= '9')
	{
		info->prec = ft_atoi(format + info->i);
		while (format[info->i] >= '0' && format[info->i] <= '9'
		&& format[info->i])
			info->i++;
	}
	else
		info->prec = 0;
	return (1);
}

int		add_length_modifier(const char *format, t_info *info)
{
	char c;

	c = format[info->i];
	info->length[1] = 0;
	if (c && is_instr(LENGTH_FLAGS, c))
	{
		info->length[0] = c;
		info->i++;
		c = format[info->i];
		if (info->length[0] == 'h' && c == 'h')
		{
			info->length[1] = c;
			info->i++;
		}
		else if (info->length[0] == 'l' && c == 'l')
		{
			info->length[1] = c;
			info->i++;
		}
	}
	return (1);
}

int		add_flags(const char *format, t_info *info)
{
	if (!add_behavior_flags(format, info))
		return (0);
	if (!add_field_width(format, info))
		return (0);
	if (!add_precision(format, info))
		return (0);
	if (!add_length_modifier(format, info))
		return (0);
	return (1);
}
