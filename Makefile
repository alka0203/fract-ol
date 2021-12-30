# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 18:12:56 by asanthos          #+#    #+#              #
#    Updated: 2021/12/14 17:24:42 by asanthos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =	srcs/main.c srcs/fractals.c srcs/colour.c srcs/hooks.c srcs/fractals_bonus.c
OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g3

$(NAME): ${OBJS}
		@make -C ./minilibx
		@make -C ./ft_libft
		@mv ./minilibx/libmlx.a ./srcs/libmlx.a
		@mv ./ft_libft/libft.a ./srcs/libft.a
		$(CC) $(CFLAGS) $(SRCS) ./srcs/libft.a ./srcs/libmlx.a -Ofast -L minilibx -framework OpenGL -framework AppKit -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}
		@make clean -C ./minilibx
		@make clean -C ./ft_libft

fclean:	clean
		${RM} ${NAME}
		@make fclean -C ./ft_libft

re:		fclean all
