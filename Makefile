# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 14:11:42 by mvann             #+#    #+#              #
#    Updated: 2017/11/14 16:53:50 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
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

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
