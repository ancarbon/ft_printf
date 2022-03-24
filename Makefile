# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 16:26:20 by ancarbon          #+#    #+#              #
#    Updated: 2022/03/22 18:05:18 by ancarbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

#BNUS =

OBJS = ${SRCS:.c=.o}
#BONUSOBJS = ${BNUS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBC = ar -crs

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${OBJS}

# bonus: ${BONUSOBJS}
#	${LIBC} ${BONUSOBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
