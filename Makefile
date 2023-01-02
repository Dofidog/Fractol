# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 12:19:54 by tpaaso            #+#    #+#              #
#    Updated: 2023/01/02 14:29:49 by tpaaso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = libft/libft.a src/*.c

CCFL = gcc -Wall -Wextra -Werror -L /usr/local/lib -lmlx -I /minilibx/ -framework OpenGL -framework AppKit

LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CCFL) -o $(NAME) $(SRCS)

clean:
	@/bin/rm -f $(OBJ)5
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

proper: all clean

.PHONY = all $(NAME) clean fclean re
