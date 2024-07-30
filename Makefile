# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkobeliev <rkobeliev@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 15:12:09 by rkobelie          #+#    #+#              #
#    Updated: 2024/07/18 18:48:24 by rkobeliev        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =  $(wildcard cleaners/*.c errors_utils/*.c get_next_line/*.c libft_utils/*.c \
	validation/*.c) main.c

OBJS = ${SRCS:.c=.o}


CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
