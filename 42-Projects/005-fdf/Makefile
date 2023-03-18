# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/03/18 14:06:12 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := fdf
NAMEB := fdf_bonus

# Directories for source, object and libraries
SRC_DIR := ./srcs
OBJ_DIR := ./objs
BSRC_DIR := ./bonus/srcs
HDR_DIR := ./incl
FTLIB_DIR := ./libs/libft
FTLIB := $(FTLIB_DIR)/libft.a
BHDR_DIR := ./bonus/incl

# Compilation flags
MFLAG := -lbsd -lmlx -lXext -lX11 -lm
CFLAGS := -Wall -Wextra -Werror -I $(HDR_DIR)

# Source files
FUN := fdf.c bresenham.c color.c image.c management.c maptreat.c matrix_core.c matrix_op.c
FUNB := fdf_bonus.c conic_bonus.c image_bonus.c input_bonus.c move_bonus.c

# Object files
OBJ := $(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ := $(filter-out $(OBJ_DIR)/fdf.o, $(OBJ)) $(FUNB:%.c=$(OBJ_DIR)/%.o)

all: putdir $(NAME)

$(NAME): $(FTLIB) $(OBJ)
	@cc $(OBJ) $(FTLIB) $(MFLAG) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@cc $(CFLAGS) -c $< -o $@

putdir:
	@[ -d ./objs ] || mkdir -p ./objs

clean:
	@$(MAKE) -C $(FTLIB_DIR) clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) fclean
	@[ -f ./fdf ] && rm fdf && echo fdf cleaned || echo Program fdf isn\'t compiled
	@[ -f ./fdf_bonus ] && rm fdf_bonus && echo bonus cleaned || echo bonus fdf isn\'t compiled

bonus: putdir $(NAMEB)

$(NAMEB): $(FTLIB) $(OBJ) $(BOBJ)
	@cc $(BOBJ) $(FTLIB) $(MFLAG) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@cc $(CFLAGS) -c $< -o $@

re: fclean all

.PHONY: all bonus putdir clean fclean re
