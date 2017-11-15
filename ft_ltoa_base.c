/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:34:26 by mvann             #+#    #+#             */
/*   Updated: 2017/11/13 21:09:45 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_pow(long n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_pow(n, pow - 1));
}

static int	ft_find_pow(long n, int base)
{
	int		pow;

	n = n > 0 ? n : n * -1;
	pow = 0;
	while (n >= base)
	{
		n /= base;
		pow++;
	}
	return (pow);
}

static char	*ft_build_str(int uppercase, long value, int base, int negative)
{
	int		len;
	int		i;
	int		pow;
	char	*digits;
	char	*out;

	pow = ft_find_pow(value, base);
	len = 1 + pow + negative;
	out = (char *)malloc(sizeof(char) * len + 1);
	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	i = negative;
	while (i < len)
	{
		out[i] = digits[value / ft_pow(base, pow)];
		value = value % ft_pow(base, pow);
		pow--;
		i++;
	}
	if (negative)
		out[0] = '-';
	out[len] = '\0';
	return (out);
}

char		*ft_build_longmin(void)
{
	int		i;
	char	*min;
	char	*out;

	*min = "-9223372036854775808";
	out = (char *)malloc(sizeof(char) * 20);
	i = 0;
	while (i < 20)
	{
		out[i] = min[i];
		i++;
	}
	return (out);
}

char		*ft_ltoa_base(long value, int base, int uppercase)
{
	int		len;
	int		negative;
	long	min;

	min = -9223372036854775808ul;
	if (value == min)
		return (ft_build_longmin());
	negative = value < 0;
	len = 1 + ft_find_pow(value, base) + negative;
	if (negative)
		value = value * -1;
	return (ft_build_str(uppercase, value, base, negative));
}
