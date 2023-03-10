# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/03/10 15:41:41 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = ./srcs/
HDR = -I ./incl/
FUN = fdf.c bresenham.c color.c image.c management.c maptreat.c matrix_core.c matrix_op.c conic_bonus.c image_bonus.c input_bonus.c move_bonus.c
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

putdir: lookfmlx
	@mkdir -p objs
#	@[ -f $(FTLIB) ] && echo libft is already built || make only -C ./libs/libft/

lookfmlx:
		@[ -f $(MLXINCL) ] && echo building fdf... || echo It seems your mlx.h isn\'t at /usr/local/include

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
#	@[ -f $(FTLIB) ] && make fclean -C ./libs/libft/ || echo libft already removed
	@[ -f ./fdf ] && rm fdf && echo fdf cleaned || echo Program fdf isn\'t compiled

re: fclean all

.PHONY: all putdir lookfmlx clean fclean re

