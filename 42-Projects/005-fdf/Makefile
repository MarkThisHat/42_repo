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
CFLAG = -Wall -Wextra -Werror
MFLAG = -lbsd -lmlx -lXext -lX11 -lm
PFUNC = $(addprefix $(SRC), $(FUN))
FTLIB = ./libs/libft/libft.a
OBJ = $(FUN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAG) $(HDR) $(addprefix ./objs/, $(FUN:.c=.o)) $(FTLIB) $(MFLAG) -o fdf

$(OBJ): putdir
	cc $(CFLAG) -c ./srcs/$(@:.o=.c) $(HDR) -o ./objs/$@ $(MFLAG)

putdir:
	@mkdir -p objs
	@[ -f $(FTLIB) ] && echo libft is already built || make only -C ./libs/libft/

learn:
	gcc -Wall -Werror -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

unu:
	gcc -Wall -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

gambs:
	cc -Wall -Werror -Wextra ./srcs/* -I ./incl/ ./libs/libft/libft.a -lbsd -lmlx -lXext -lX11 -lm -o fdf

val:
	gcc -Wall -Wextra -Werror -g ./srcs/fdf.c ./libs/libft/libft.a -I ./incl -lbsd -lmlx -lXext -lX11 -lm

test:
	@[ -f $(addprefix ./objs/, $(FUN:.c=.o)) ] || echo Object file\(s\) missing

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean:
	@[ -f $(FTLIB) ] && make fclean -C ./libs/libft/ || echo libft already removed
	@[ -d ./objs ] && rm -rf ./objs || echo Directory objs doesn\'t exist
	@[ -f ./fdf ] && rm fdf || echo Program fdf isn\'t compiled

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out
#garbage gcc -Wall -Wextra -Lmlx_linux -I /usr/local/include -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz /usr/local/lib/libmlx.a minitest.c