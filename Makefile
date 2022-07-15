# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 16:29:54 by ancarbon          #+#    #+#              #
#    Updated: 2022/07/15 15:36:50 by ancarbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_parse.c ft_char_utils.c \
ft_decnbr_utils.c ft_hex_utils.c ft_ptr_utils.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBC = ar -crs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all