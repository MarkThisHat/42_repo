# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/03/07 11:58:29 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ./srcs/
HDR = -I ./incl/
FUN = fdf.c fdf_bonus.c bresenham.c image.c management.c maptreat.c matrix_core.c matrix_op.c mouse_bonus.c move_bonus.c color.c
CFLAG = -Wall -Wextra -Werror
MLXINCL = /usr/local/include/mlx.h
MFLAG = -lbsd -lmlx -lXext -lX11 -lm
PFUNC = $(addprefix $(SRC), $(FUN))
FTLIB = ./libs/libft/libft.a
OBJ = $(FUN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(CFLAG) $(HDR) $(addprefix ./objs/, $(FUN:.c=.o)) $(FTLIB) $(MFLAG) -g -o fdf && echo done || echo Something went wrong

$(OBJ): putdir
	@cc $(CFLAG) -c ./srcs/$(@:.o=.c) $(HDR) -o ./objs/$@

putdir: look4mlx
	@mkdir -p objs
#	@[ -f $(FTLIB) ] && echo libft is already built || make only -C ./libs/libft/

look4mlx:
		@[ -f $(MLXINCL) ] && echo building fdf... || echo It seems your mlx.h isn\'t at /usr/local/include

learn:
	gcc -Wall -Werror -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

unu:
	gcc -Wall -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

gambs:
	cc -Wall -Werror -Wextra ./srcs/* -I ./incl/ ./libs/libft/libft.a -lbsd -lmlx -lXext -lX11 -lm -o fdf

val:
	gcc -Wall -Wextra -Werror -g ./srcs/fdf.c ./libs/libft/libft.a -I ./incl -lbsd -lmlx -lXext -lX11 -lm

test:
	@[ -f $(MLXINCL) ] && echo let\'s go  || echo not here


clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
#	@[ -f $(FTLIB) ] && make fclean -C ./libs/libft/ || echo libft already removed
	@[ -f ./fdf ] && rm fdf && echo fdf cleaned || echo Program fdf isn\'t compiled

re: fclean all

.PHONY: all putdir look4mlx clean fclean re

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out
#garbage gcc -Wall -Wextra -Lmlx_linux -I /usr/local/include -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz /usr/local/lib/libmlx.a minitest.c