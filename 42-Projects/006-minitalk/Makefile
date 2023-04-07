# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/04/07 17:03:05 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME1 := server
NAME2 := client

# Directories for source, object and libraries
SRC_DIR := ./srcs
OBJ_DIR := ./objs
BSRC_DIR := ./bonus/srcs
HDR_DIR := ./incl
FTLIB_DIR := ./libs/libft
FTLIB := $(FTLIB_DIR)/libft.a

# Compilation flags
CFLAGS := -Wall -Wextra -Werror -I $(HDR_DIR)

# Source files
FUN := mini_utils.c

# Object files
C_OBJ := $(OBJ_DIR)/$(NAME2).o $(FUN:%.c=$(OBJ_DIR)/%.o)
S_OBJ := $(OBJ_DIR)/$(NAME1).o $(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ := $(FUN:%.c=$(OBJ_DIR)/%.o)

all: putdir $(NAME1) $(NAME2)

test:
	@echo $(C_OBJ)

$(NAME1): $(S_OBJ) $(FTLIB)
	cc $(S_OBJ) $(FTLIB) -o $@

$(NAME2): $(C_OBJ) $(FTLIB)
	cc $(C_OBJ) $(FTLIB) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(CFLAGS) -c $< -o $@

putdir:
	@[ -d ./objs ] || mkdir -p ./objs


bonus: putdir $(NAMEB1)

$(NAMEB1): $(FTLIB) $(BOBJ1)
	@cc $(BOBJ) $(FTLIB) $(MFLAG) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(FTLIB_DIR) clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) fclean
	@[ -f ./$(NAME2) ] && rm $(NAME2) && echo $(NAME2) cleaned || echo Program $(NAME2) isn\'t compiled
	@[ -f ./$(NAME1) ] && rm $(NAME1) && echo $(NAME1) cleaned || echo Program $(NAME1) isn\'t compiled
	@[ -f ./minitalk_bonus ] && rm minitalk_bonus && echo bonus cleaned || echo bonus minitalk isn\'t compiled

re: fclean all

.PHONY: all bonus client server putdir clean fclean re
