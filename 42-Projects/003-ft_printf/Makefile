# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:23:12 by maalexan          #+#    #+#              #
#    Updated: 2022/10/16 00:10:19 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
FLAGS = -Wall -Werror -Wextra
SRC = ./
HDR = -I ./
FUNC = ft_printf.c ft_printf_utils.c
BONI = 
JOINSRCFUNC = ${addprefix ${SRC}, ${FUNC}}
JOINBONUS = ${addprefix ${SRC}, ${BONI}}
OBJ = ${FUNC:.c=.o}
OBONUS = ${BONI:.c=.o}

all: ${NAME}
	
${OBJ}:
		cc ${FLAGS} ${HDR} -c ${@:.o=.c}

${NAME}: ${OBJ}
		ar -rcs ${NAME} ${OBJ}

bonus: ${NAME} ${OBONUS}
	
${OBONUS}:
		cc ${FLAGS} ${HDR} -c ${@:.o=.c}
		ar -rcs ${NAME} $@

clean:
		rm -f ${OBJ} ${OBONUS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
