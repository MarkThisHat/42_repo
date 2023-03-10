# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/03/10 16:43:55 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAMEB = fdf_bonus
SRC = ./srcs/
SRCB = ./bonus/srcs
HDR = -I ./incl/
HDRB = -I ./bonus/incl
FUN = bresenham.c color.c image.c management.c maptreat.c matrix_core.c matrix_op.c
FUNB = fdf_bonus.c conic_bonus.c image_bonus.c input_bonus.c move_bonus.c
CFLAG = -Wall -Wextra -Werror
MLXINCL = /usr/local/include/mlx.h
MFLAG = -lbsd -lmlx -lXext -lX11 -lm
PFUNC = $(addprefix $(SRC), $(FUN))
FTLIB = ./libs/libft/libft.a
OBJ = $(FUN:.c=.o)
OBJB = $(FUNB:.c=.o)

all: $(NAME)

$(NAME): putfdf $(OBJ)
	@cc $(CFLAG) $(HDR) ./objs/$(NAME).o $(addprefix ./objs/, $(FUN:.c=.o)) $(FTLIB) $(MFLAG) -g -o fdf && echo done || echo Something went wrong

$(OBJ):
	@cc $(CFLAG) -c ./srcs/$(@:.o=.c) $(HDR) -o ./objs/$@

putfdf: putdir
	@cc $(CFLAG) -c ./srcs/$(NAME).c $(HDR) -o ./objs/$(NAME).o

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
	@[ -f ./fdf_bonus ] && rm fdf_bonus && echo bonus cleaned || echo bonus fdf isn\'t compiled

bonus: $(NAMEB)

$(NAMEB): $(OBJB)
	@cc $(CFLAG) $(HDR) $(HDRB) $(addprefix ./objs/, $(FUN:.c=.o)) $(addprefix ./objs/, $(FUNB:.c=.o)) $(FTLIB) $(MFLAG) -g -o fdf_bonus && echo done || echo Something went wrong

$(OBJB): putdir $(OBJ)
	@cc $(CFLAG) -c ./bonus/srcs/$(NAMEB).c $(HDRB) -o ./objs/$(NAMEB).o
	@cc $(CFLAG) -c ./bonus/srcs/$(@:.o=.c) $(HDRB) -o ./objs/$@

re: fclean all

.PHONY: all bonus putdir lookfmlx clean fclean re

