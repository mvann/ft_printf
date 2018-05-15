/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:00:29 by mvann             #+#    #+#             */
/*   Updated: 2017/11/27 15:24:26 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_pow(unsigned long n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_pow(n, pow - 1));
}

static int	ft_find_pow(unsigned long n, int base)
{
	int		pow;

	pow = 0;
	while (n >= (unsigned long)base)
	{
		n /= base;
		pow++;
	}
	return (pow);
}

static char	*ft_build_str(int uppercase, unsigned long value, int base)
{
	int		len;
	int		i;
	int		pow;
	char	*digits;
	char	*out;

	pow = ft_find_pow(value, base);
	len = 1 + pow;
	out = (char *)malloc(sizeof(char) * len + 1);
	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	i = 0;
	while (i < len)
	{
		out[i] = digits[value / ft_pow(base, pow)];
		value = value % ft_pow(base, pow);
		pow--;
		i++;
	}
	out[len] = '\0';
	return (out);
}

char		*ft_ultoa_base(unsigned long value, int base, int uppercase)
{
	return (ft_build_str(uppercase, value, base));
}
