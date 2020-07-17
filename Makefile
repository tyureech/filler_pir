# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 18:36:38 by mmahasim          #+#    #+#              #
#    Updated: 2019/09/30 15:42:26 by mmahasim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mmahasim.filler
SRC = fill_numbers.c \
	  perimetr.c \
	  placer.c \
	  main.c
LIBFT_DIR = libft
LIBS = libft/libft.a
HEADERS = filler.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(LIBS): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS) $(HEADERS)
	gcc $(FLAG) -o $(NAME) $(SRC) $(LIBS) -I $(HEADERS)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
