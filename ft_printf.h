/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:13:07 by mvann             #+#    #+#             */
/*   Updated: 2017/10/24 14:02:24 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F
# define FT_PRINT_F

# include "libft/libft.h"
# include <stdarg.h>

# define MAP_ARR_SIZE 20
# define FLAGS "#-+0 .hljz*"
# define BEHAVIOR_FLAGS "#-+0 "
# define LENGTH_FLAGS "hljz"
# define SPECIFIERS "sSpdDioOuUxXcC"

# ifndef NULL
#  define NULL (void *)0
# endif

// typedef struct	s_flags
// {
// 	int			HASH;
// 	int			DASH;
// 	int			PLUS;
// 	int			ZERO;
// 	int			SPACE;
// 	int			DOT;
// 	int			HH;
// 	int			H;
// 	int			L;
// 	int			LL;
// 	int			J;
// 	int			Z;
// }				t_flags;


typedef struct	s_info
{
	va_list		ap;
	int			i;
	int			flags;
	int			precision;
	int			min_field_width;
	char		length[2];
}				t_info;

typedef int	(*t_specifier_func)(t_info *);

int		ft_printf(const char *format, ...);
int		ft_str_iofc(char *str, char c);

int		add_flags(const char *format, t_info *info);
int		is_instr(char *str, char c);
int		is_flagged(int flags, char *str, char c);

int		put_specifier(const char *format, t_info *info);

int		print_c(t_info *info);

#endif
