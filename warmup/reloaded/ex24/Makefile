# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 21:03:39 by maalexan          #+#    #+#              #
#    Updated: 2022/09/03 21:46:22 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
SRC = ./srcs/
HDR = -I ./includes/
FUNC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
JOINSRCFUNC = ${addprefix ${SRC}, ${FUNC}}
OBJ = ${FUNC:.c=.o}

all: ${NAME}

${OBJ}:
	gcc ${FLAGS} ${HDR} -c ${JOINSRCFUNC}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
