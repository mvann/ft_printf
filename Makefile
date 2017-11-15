# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2017/11/14 16:42:21 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  ft_printf.c\
	  add_flags.c\
	  libft/*.c\
	  specifiers.c\
	  character.c\
	  cstring.c\
	  signed.c\
	  ft_ltoa_base.c\
	  ft_ultoa_base.c\
	  unsigned.c\
	  helper_functions.c\
	  mapped_functions.c

all:
	gcc -Wall -Wextra -Werror $(SRC)

test:
	gcc -Wall -Wextra -Werror $(SRC)
	./a.out | cat -e
