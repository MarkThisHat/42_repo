# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/04/24 20:47:52 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := push_swap

# Directories for source, object and libraries
SRC_DIR := ./srcs
OBJ_DIR := ./objs
BSRC_DIR := ./bonus/
HDR_DIR := ./incl
FTLIB_DIR := ./libs/libft
FTLIB := $(FTLIB_DIR)/libft.a

# Compilation flags
CFLAGS := -Wall -Wextra -Werror -I $(HDR_DIR)

# Source files
FUN := push_swap.c ps_utils.c merge_swap.c push_index.c verify_input.c a_moves.c

# Object files
OBJ := $(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ := $(BFUN:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(FTLIB)
	cc $(OBJ) $(FTLIB) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME)_bonus

$(NAME)_bonus: $(BOBJ) $(FTLIB)
	cc $(BOBJ) $(FTLIB) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(@D)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(FTLIB_DIR) clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) fclean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled
	@[ -f ./$(NAME)_bonus ] && rm $(NAME)_bonus|| echo Bonus $(NAME) isn\'t compiled

re: fclean all

.PHONY: all bonus clean fclean re
