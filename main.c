/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:35 by mvann             #+#    #+#             */
/*   Updated: 2017/10/24 14:08:22 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
// int	 printf(__const char * restrict, ...) __attribute__((__format__ (__printf__, 1,  2)));
int		main()
{
	//char str[] = "sup";
	ft_printf("%lc\n", L'Δ');
	// printf("hello%c\n", 355);


	return (0);
}
