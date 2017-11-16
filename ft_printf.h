/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvann <mvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:13:07 by mvann             #+#    #+#             */
/*   Updated: 2017/11/15 19:14:55 by mvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F
# define FT_PRINT_F

# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h> //DELETE ME #############################

# define MAP_ARR_SIZE 20
# define FLAGS "#-+0 .hljz*"
# define BEHAVIOR_FLAGS "#-+0 "
# define LENGTH_FLAGS "hljz"
# define SPECIFIERS "sSpdDioOuUxXcC%"

# ifndef NULL
#  define NULL (void *)0
# endif

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

int				ft_printf(const char *format, ...);
int				ft_str_iofc(char *str, char c);
int				putnchars(char c, int n);
int				put_str_retlen(char *s);

int				add_flags(const char *format, t_info *info);
int				is_instr(char *str, char c);
int				is_flagged(int flags, char *str, char c);
void			add_flag(t_info *info, char *str, char c);

int				put_specifier(const char *format, t_info *info);

int				print_c(t_info *info, int use_percentage);
int				print_character(t_info *info);
int				print_percentage(t_info *info);


int				print_s(t_info *info);

int				print_signed_int(t_info *info);
int				print_number(t_info *info, int base, int uppercase, char *s);
char			*ft_ltoa_base(long value, int base, int sign, int space);
char			*ft_ultoa_base(unsigned long value, int base, int uppercase);


int				print_unsigned(t_info *info, int base, int uppercase);
unsigned long	get_unsigned(char l[2], t_info *info);
int				print_long_int(t_info *info);
int				print_unsigned_oct(t_info *info);
int				print_unsigned_hex(t_info *info);
int				print_unsigned_hex_upper(t_info *info);
int				print_unsigned_int(t_info *info);
int				print_long_unsigned_int(t_info *info);


#endif
