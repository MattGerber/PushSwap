# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magerber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 10:32:42 by magerber          #+#    #+#              #
#    Updated: 2019/09/04 13:14:01 by magerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB = libft
# CH = checker
# PS = push_swap
# CC = gcc
# FLAGS = -Wall -Werror -Wextra
# SRC = ./Srcs/
# INC = ./Includes/
# OBJ = ./Srcs/
# OPS = -I$(INC) -I./libft -lft -L./libft
# HDR = ./Includes/push_swap.h

# OBJ_CH = $(OBJ)checker.o $(OBJ)error_check.o $(OBJ)list_operations_push.o 
# OBJ_CH += $(OBJ)list_operations_reverse_rotate.o $(OBJ)list_operations_rotate.o
# OBJ_CH += $(OBJ)list_operations_swap.o $(OBJ)manipulate_stack.o

# all: $(LIB) $(CH)

# $(LIB): relib cleanlib
# 	@echo "[$(LIB)] compiled"

# %.o: $(SRC)%.c $(HDR)
# 	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

# $(CH): $(OBJ_CH)
# 	@$(CC) -o $(CH) $(FLAGS) $(OPTIONS) $(OBJ_CH) 
# 	@echo "[$(CH)] compiled"

# clean: cleanlib
# 	@/bin/rm -f $(SRC)*.o
# 	@echo "Object files removed"

# fclean: clean fcleanlib
# 	@/bin/rm -f $(CH)
# 	@echo "[$(NAME_CH)]"

# re: fclean all

# relib:
# 	@$(MAKE) -C ./libft re

# cleanlib:
# 	@$(MAKE) -C ./libft clean

# fcleanlib: cleanlib
# 	@$(MAKE) -C ./libft fclean


LIB = libft
NAME_CH = checker
NAME_PS = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
INC_DIR = ./includes/
OBJ_DIR = ./srcs/
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft
HDR = ./includes/push_swap.h

OBJ_CH = $(OBJ_DIR)checker.o $(OBJ_DIR)error_check.o $(OBJ_DIR)list_operations_push.o
OBJ_CH += $(OBJ_DIR)list_operations_reverse_rotate.o $(OBJ_DIR)list_operations_rotate.o
OBJ_CH += $(OBJ_DIR)list_operations_swap.o $(OBJ_DIR)manipulate_stack.o

OBJ_PS = $(OBJ_DIR)push_swap.o $(OBJ_DIR)error_check.o $(OBJ_DIR)manipulate_stack.o
OBJ_PS += $(OBJ_DIR)list_operations_reverse_rotate.o $(OBJ_DIR)list_operations_rotate.o
OBJ_PS += $(OBJ_DIR)list_operations_swap.o $(OBJ_DIR)list_operations_push.o
OBJ_PS += $(OBJ_DIR)sort_algos.o

all: $(LIB) $(NAME_CH) $(NAME_PS)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME_CH): $(OBJ_CH)
	@$(CC) -o $(NAME_CH) $(FLAGS) $(OPTIONS) $(OBJ_CH) 
	@echo "[$(NAME_CH)] compiled"

$(NAME_PS): $(OBJ_PS)
	@$(CC) -o $(NAME_PS) $(FLAGS) $(OPTIONS) $(OBJ_PS) 
	@echo "[$(NAME_PS)] compiled"

clean: cleanlib
	@/bin/rm -f $(SRC_DIR)*.o
	@echo "Object files removed"

fclean: clean fcleanlib
	@/bin/rm -f $(NAME_CH)
	@echo "[$(NAME_CH)]" 

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean