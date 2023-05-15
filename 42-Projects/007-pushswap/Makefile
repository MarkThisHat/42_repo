# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/05/14 12:07:55 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := push_swap
NAMEB := checker

# Directories for source, object and libraries
SRC_DIR := ./srcs
OBJ_DIR := ./objs
BSRC_DIR := ./bonus/srcs
HDR_DIR := ./incl
FTLIB_DIR := ./libs/libft
FTLIB := $(FTLIB_DIR)/libft.a

# Compilation flags
CFLAGS := -Wall -Wextra -Werror -I $(HDR_DIR)
BCFLAGS := -Wall -Wextra -Werror -I ./bonus/incl

# Source files
FUN := a_moves.c b_moves.c multi_swap.c merge_swap.c move_swap.c node_swap.c ps_utils.c push_check.c push_index.c push_swap.c push_sol.c solve_swap.c solc_swap.c solc_utils.c small_swap.c print_swap.c opt_swap.c
BFUN := checker_bonus.c ps_utils.c push_check.c push_check_bonus.c node_swap.c a_moves.c b_moves.c multi_swap.c

# Object files
OBJ := $(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ := $(BFUN:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(FTLIB)
	cc $(OBJ) $(FTLIB) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR) --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAMEB)

$(NAMEB): $(BOBJ) $(FTLIB)
	cc $(BOBJ) $(FTLIB) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(@D)
	@cc $(BCFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(FTLIB_DIR) --silent clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) --silent fclean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo Program $(NAME) isn\'t compiled
	@[ -f ./$(NAMEB) ] && rm $(NAMEB)|| echo Bonus $(NAMEB) isn\'t compiled

re: fclean all

.PHONY: all bonus clean fclean re
