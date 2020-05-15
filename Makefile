# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magerber <magerber@student.wethinkcode.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 10:32:42 by magerber          #+#    #+#              #
#    Updated: 2020/02/12 15:11:11 by magerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

  
PNME = push_swap
CNME = checker
LIB = libft/libft.a
MAKELIB = -C libft
FLGS=-Wall -Werror -Wextra
DBFLG =-Wall -Werror -Wextra -g
PSRC= Includes/push_swap.h ./srcs/error_check.c ./srcs/list_operations*.c ./srcs/manipulate_stack.c \
./srcs/sort_algos.c ./srcs/algo_helpers.c ./srcs/stack_minmax.c ./srcs/algohelpersv2.c ./srcs/start.c libft/*.c  ./srcs/push_swap.c
CSRC= Includes/push_swap.h ./srcs/checker.c ./srcs/error_check.c ./srcs/list_operations*.c ./srcs/manipulate_stack.c \
./srcs/sort_algos.c ./srcs/algo_helpers.c ./srcs/stack_minmax.c ./srcs/algohelpersv2.c ./srcs/start.c libft/*.c 

all: $(MAKELIB) $(CNME) $(PNME)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)

$(CNME):
	gcc $(FLGS) $(CSRC) -o $(CNME)

$(PNME):
	gcc $(FLGS) $(PSRC) -o $(PNME)

ps:
	gcc $(FLGS) $(CSRC) -o $(CNME)
	gcc $(FLGS) $(PSRC) -o $(PNME)

db:
	gcc $(DBFLG) $(CSRC) -ggdb3 -o $(CNME)
	gcc $(DBFLG) $(PSRC) -ggdb3 -o $(PNME)

clean:
	rm -fr $(CNME) $(PNME) $(CNME).dSYM $(PNME).dSYM
	rm -f libft/*.o

fclean: clean
	rm -f libft/*.o libft/libft.a

re: clean all

redb: clean db

# LIB = libft
# NAME_CH = checker
# NAME_PS = push_swap
# CC = gcc
# FLAGS = -Wall -Werror -Wextra 
# SRC_DIR = ./srcs/
# INC_DIR = ./includes/
# OBJ_DIR = ./srcs/
# OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft
# HDR = ./includes/push_swap.h

# OBJ_CH = $(OBJ_DIR)checker.o $(OBJ_DIR)error_check.o $(OBJ_DIR)list_operations_push.o
# OBJ_CH += $(OBJ_DIR)list_operations_reverse_rotate.o $(OBJ_DIR)list_operations_rotate.o
# OBJ_CH += $(OBJ_DIR)list_operations_swap.o $(OBJ_DIR)manipulate_stack.o 
# OBJ_CH += $(OBJ_DIR)sort_algos.o $(OBJ_DIR)algo_helpers.o $(OBJ_DIR)stack_minmax.o
# OBJ_CH += $(OBJ_DIR)algohelpersv2.o $(OBJ_DIR)start.o

# OBJ_PS = $(OBJ_DIR)push_swap.o $(OBJ_DIR)error_check.o $(OBJ_DIR)manipulate_stack.o
# OBJ_PS += $(OBJ_DIR)list_operations_reverse_rotate.o $(OBJ_DIR)list_operations_rotate.o
# OBJ_PS += $(OBJ_DIR)list_operations_swap.o $(OBJ_DIR)list_operations_push.o
# OBJ_PS += $(OBJ_DIR)sort_algos.o $(OBJ_DIR)algo_helpers.o $(OBJ_DIR)stack_minmax.o
# OBJ_PS += $(OBJ_DIR)algohelpersv2.o $(OBJ_DIR)start.o  $(OBJ_DIR)print_stack.o

# all: $(LIB) $(NAME_CH) $(NAME_PS)

# $(LIB): relib cleanlib
# 	@echo "[$(LIB)] compiled"

# %.o: $(SRC_DIR)%.c $(HDR)
# 	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

# $(NAME_CH): $(OBJ_CH)
# 	@$(CC) -o $(NAME_CH) $(FLAGS) $(OPTIONS) $(OBJ_CH) 
# 	@echo "[$(NAME_CH)] compiled"

# $(NAME_PS): $(OBJ_PS)
# 	$(CC) -o  $(NAME_PS) $(FLAGS) $(OPTIONS) $(OBJ_PS) 
# 	@echo "[$(NAME_PS)] compiled"


# clean: cleanlib
# 	@/bin/rm -f $(SRC_DIR)*.o
# 	@echo "Object files removed"

# fclean: clean fcleanlib
# 	@/bin/rm -f $(NAME_CH)
# 	@echo "[$(NAME_CH)]" 

# re: fclean all

# relib:
# 	@$(MAKE) -C ./libft re

# cleanlib:
# 	@$(MAKE) -C ./libft clean

# fcleanlib: cleanlib
# 	@$(MAKE) -C ./libft fclean

