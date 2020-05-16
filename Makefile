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