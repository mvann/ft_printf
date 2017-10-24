# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2017/10/23 14:21:24 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  ft_printf.c\
	  add_flags.c\
	  libft/*.c\
	  specifiers.c\
	  character.c

all:
	gcc -Wall -Wextra -Werror $(SRC)

test:
	gcc -Wall -Wextra -Werror $(SRC)
	./a.out
