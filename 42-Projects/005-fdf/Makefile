# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/01/29 11:09:02 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ./srcs/
HDR = -I ./incl/
FUN = fdf.c management.c validators.c maptreat.c antialias.c utils.c
CFLAG = -Wall -Wextra -Werror -lm
MFLAG = -lbsd -lmlx -lXext -lX11
PFUNC = $(addprefix $(SRC), $(FUN))
FTLIB = ./libs/libft/libft.a
OBJ = $(FUN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(HDR) $(addprefix ./objs/, $(FUN:.c=.o)) $(FTLIB)

$(OBJ): putdir
	cc $(CFLAG) $(MFLAG) $(HDR) -c ./srcs/$(@:.o=.c) -o ./objs/$@

putdir:
	mkdir -p objs

learn:
	gcc -Wall -Werror -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

unu:
	gcc -Wall -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

fdfold:
	gcc -Wall -Wextra -Werror ./srcs/fdf.c ./libs/libft/libft.a -I ./incl

val:
	gcc -Wall -Wextra -Werror -g ./srcs/fdf.c ./libs/libft/libft.a -I ./incl -lbsd -lmlx -lXext -lX11 -lm

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out
#garbage gcc -Wall -Wextra -Lmlx_linux -I /usr/local/include -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz /usr/local/lib/libmlx.a minitest.c