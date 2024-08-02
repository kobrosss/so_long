# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:12:09 by rkobelie          #+#    #+#              #
#    Updated: 2024/08/02 02:07:51 by rkobelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =  $(wildcard cleaners/*.c errors_utils/*.c get_next_line/*.c libft_utils/*.c \
	validation/*.c mlx/*.c ft_printf/*.c) main.c

OBJS = ${SRCS:.c=.o}

LIBS = -lX11 -Lminilibx-linux -lmlx_Linux -lXext
MINILIBX = minilibx-linux/
FT_PRINTF = ft_printf/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	make -C $(MINILIBX)
	make -C $(FT_PRINTF)
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBS}

clean:
	@${RM} ${OBJS}

fclean: clean
	make clean -C $(MINILIBX)
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
