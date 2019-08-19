# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magerber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 15:09:42 by magerber          #+#    #+#              #
#    Updated: 2019/08/19 12:40:01 by magerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
OBJECT = *.o
SOURCE = ft_atoi.c \
        ft_bzero.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_itoa.c \
        ft_memalloc.c \
        ft_memccpy.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memdel.c \
        ft_memmove.c \
        ft_memset.c \
        ft_putchar.c \
        ft_putchar_fd.c \
        ft_putendl.c \
        ft_putendl_fd.c \
        ft_putnbr.c \
        ft_putnbr_fd.c \
        ft_putstr.c \
        ft_putstr_fd.c \
        ft_strcat.c \
        ft_strchr.c \
        ft_strclr.c \
        ft_strcmp.c \
        ft_strcpy.c \
        ft_strdel.c \
        ft_strdup.c \
        ft_strequ.c \
        ft_striter.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_strlcat.c \
        ft_strlen.c \
        ft_strmap.c \
        ft_strmapi.c \
        ft_strncat.c \
        ft_strncmp.c \
        ft_strncpy.c \
        ft_strnequ.c \
        ft_strnew.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_strstr.c \
        ft_strsub.c \
        ft_strsplit.c \
        ft_strtrim.c \
        ft_toupper.c \
        ft_tolower.c \
		ft_wordcount.c \
		ft_wordlen.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_intsize.c \
		ft_convert.c \
		ft_isupper.c \
		ft_strndup.c \
		get_next_line.c

OPTIONS = -c -I.

all: $(NAME)

$(NAME):
		gcc $(FLAGS) $(OPTIONS) $(SOURCE)
		ar rc $(NAME) $(OBJECT)
		ranlib $(NAME)

so:
	gcc -c ft_*.c -Wall -Wextra -Werror
	gcc -shared -o libft.so -fPIC ft*.o
	rm *.o

clean:
		/bin/rm -f $(OBJECT)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
