/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:35 by mvann             #+#    #+#             */
/*   Updated: 2017/11/13 21:02:00 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //delete this whole file actually
#include "ft_printf.h"
// int	 printf(__const char * restrict, ...) __attribute__((__format__ (__printf__, 1,  2)));
int		main()
{
	//char str[] = "sup";
	// ft_printf("%lc\n", L'Δ');
	// ft_printf("%ls\n", (wchar_t *)"hell there");

	ft_printf("%#.0o\n", 0);

	return (0);
}
