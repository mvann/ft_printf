# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2017/11/14 17:49:27 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
SRC = main.c\
	  ft_printf.c\
	  add_flags.c\
	  specifiers.c\
	  character.c\
	  cstring.c\
	  signed.c\
	  ft_ltoa_base.c\
	  ft_ultoa_base.c\
	  unsigned.c\
	  helper_functions.c\
	  mapped_functions.c

all: $(NAME)

$(NAME):
	@cd libft && make
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(SRC:.c=.o) libft/*.o
	@ranlib $(NAME)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean

re: fclean all
