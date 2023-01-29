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

all:
	gcc -Wall -Wextra -Werror ./srcs/fdf.c ./libs/libft/libft.a -I ./incl -lbsd -lmlx -lXext -lX11 -lm

learn:
	gcc -Wall -Werror -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

unu:
	gcc -Wall -Wextra ./learning/minitest.c -lbsd -lmlx -lXext -lX11 -lm

fdf:
	gcc -Wall -Wextra -Werror ./srcs/fdf.c ./libs/libft/libft.a -I ./incl

val:
	gcc -Wall -Wextra -Werror -g ./srcs/fdf.c ./libs/libft/libft.a -I ./incl -lbsd -lmlx -lXext -lX11 -lm

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out
#garbage gcc -Wall -Wextra -Lmlx_linux -I /usr/local/include -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz /usr/local/lib/libmlx.a minitest.c