# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobelie <rkobelie@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:12:09 by rkobelie          #+#    #+#              #
#    Updated: 2024/08/03 03:05:14 by rkobelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = cleaners/tablice_cleaner.c errors_utils/errors.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c libft_utils/ft_bzero.c libft_utils/ft_calloc.c \
	libft_utils/ft_memcpy.c libft_utils/ft_split.c libft_utils/ft_strdup.c \
	validation/border_validation.c validation/collecting_validation.c \
	validation/C_P_E_validation.c validation/form_validation.c \
	validation/map_reader.c validation/P_E_amount.c validation/validation.c \
	mlx/mlx_1.c mlx/mlx_2.c main.c

OBJS = ${SRCS:.c=.o}

LIBS = -lX11 -Lminilibx-linux -lmlx_Linux -lXext ft_printf/libftprintf.a
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
	make clean -C $(FT_PRINTF)
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
