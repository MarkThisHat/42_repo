# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/04/11 17:27:46 by maalexan         ###   ########.fr        #
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
FUN := mini_utils.c linked_list.c

# Object files
C_OBJ := $(OBJ_DIR)/$(NAME2).o $(FUN:%.c=$(OBJ_DIR)/%.o)
S_OBJ := $(OBJ_DIR)/$(NAME1).o $(FUN:%.c=$(OBJ_DIR)/%.o)
C_BOBJ := $(FUN:%.c=$(OBJ_DIR)/%_bonus.o) $(OBJ_DIR)/$(NAME2)_bonus.o
S_BOBJ := $(FUN:%.c=$(OBJ_DIR)/%_bonus.o) $(OBJ_DIR)/$(NAME1)_bonus.o

all: $(NAME1) $(NAME2)

test:
	@echo $(BOBJ)

$(NAME1): $(S_OBJ) $(FTLIB)
	cc $(S_OBJ) $(FTLIB) -o $@

$(NAME2): $(C_OBJ) $(FTLIB)
	cc $(C_OBJ) $(FTLIB) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME1)_bonus $(NAME2)_bonus

$(NAME1)_bonus: $(S_BOBJ) $(FTLIB)
	cc $(S_BOBJ) $(FTLIB) -o $@

$(NAME2)_bonus: $(C_BOBJ) $(FTLIB)
	cc $(C_BOBJ) $(FTLIB) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@mkdir -p $(@D)
	@cc $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(FTLIB_DIR) clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) fclean
	@[ -f ./$(NAME2) ] && rm $(NAME2) || echo Program $(NAME2) isn\'t compiled
	@[ -f ./$(NAME1) ] && rm $(NAME1) || echo Program $(NAME1) isn\'t compiled
	@[ -f ./$(NAME2)_bonus ] && rm $(NAME2)_bonus|| echo Bonus $(NAME2) isn\'t compiled
	@[ -f ./$(NAME1)_bonus ] && rm $(NAME1)_bonus|| echo Bonus $(NAME1) isn\'t compiled

re: fclean all

.PHONY: all bonus clean fclean re
