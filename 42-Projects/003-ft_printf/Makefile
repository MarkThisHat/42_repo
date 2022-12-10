# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:23:12 by maalexan          #+#    #+#              #
#    Updated: 2022/12/10 01:54:57 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = ./
HDR = -I ./
FUNC = ft_printf.c ft_printf_utils.c
BONI = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_flags_bonus.c
JOINSRCFUNC = ${addprefix ${SRC}, ${FUNC}}
JOINBONUS = ${addprefix ${SRC}, ${BONI}}
OBJ = ${FUNC:.c=.o}
OBONUS = ${BONI:.c=.o}

all: ${NAME}
	
${OBJ}:
		cc ${FLAGS} ${HDR} -c ${@:.o=.c}

${NAME}: ${OBJ}
		ar -rcs ${NAME} ${OBJ}

bonus: ${OBONUS}
		ar -rcs ${NAME} ${OBONUS}
	
${OBONUS}:
		cc ${FLAGS} ${HDR} -c ${@:.o=.c}
		ar -rcs ${NAME} $@

clean:
		rm -f ${OBJ} ${OBONUS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
