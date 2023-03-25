# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalexan <maalexan@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 11:13:39 by maalexan          #+#    #+#              #
#    Updated: 2023/03/18 16:26:39 by maalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME := server
NAMEB := minitalk_bonus

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
FUN := server.c
FUNB := server_bonus.c

# Object files
OBJ := $(FUN:%.c=$(OBJ_DIR)/%.o)
BOBJ := $(FUNB:%.c=$(OBJ_DIR)/%.o)

all: putdir $(NAME)

$(NAME): $(FTLIB) $(OBJ)
	@cc $(OBJ) $(FTLIB) -o $@

$(FTLIB):
	@$(MAKE) -C $(FTLIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(CFLAGS) -c $< -o $@

bonus: putdir $(NAMEB)

$(NAMEB): $(FTLIB) $(OBJ) $(BOBJ)
	@cc $(BOBJ) $(FTLIB) $(MFLAG) -o $@

$(OBJ_DIR)/%.o: $(BSRC_DIR)/%.c
	@cc $(CFLAGS) -c $< -o $@

putdir:
	@[ -d ./objs ] || mkdir -p ./objs

clean:
	@$(MAKE) -C $(FTLIB_DIR) clean
	@[ -d ./objs ] && rm -rf ./objs || echo Object directory doesn\'t exist

fclean: clean
	@$(MAKE) -C $(FTLIB_DIR) fclean
	@[ -f ./server ] && rm server && echo server cleaned || echo Program server isn\'t compiled
	@[ -f ./minitalk_bonus ] && rm minitalk_bonus && echo bonus cleaned || echo bonus minitalk isn\'t compiled

re: fclean all

.PHONY: all bonus putdir clean fclean re
