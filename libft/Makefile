# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 16:17:49 by iberchid          #+#    #+#              #
#    Updated: 2019/10/10 16:12:57 by iberchid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memndup.c ft_memset.c ft_nrev.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_repchr.c ft_rev.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		ft_toupper.c ft_whitespace.c get_next_line.c alloc_fun.c free_fun.c \
		ft_error.c ft_alloc.c ft_free.c ft_strfind.c ft_to_stack.c cut_until.c \
		get_text.c print_hex.c ft_isnum.c
OFILES = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
		 ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
		 ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		 ft_memcpy.o ft_memdel.o ft_memmove.o ft_memndup.o ft_memset.o ft_nrev.o \
		 ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
		 ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_repchr.o ft_rev.o ft_strcat.o \
		 ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
		 ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
		 ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
		 ft_strndup.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o \
		 ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
		 ft_toupper.o ft_whitespace.o get_next_line.o alloc_fun.o free_fun.o \
		 ft_error.o ft_alloc.o ft_free.o ft_strfind.o ft_to_stack.o cut_until.o \
		 get_text.o print_hex.o ft_isnum.o
NAME = libft.a
HEADER = libft.h
C = gcc
FLAGS = -Werror -Wall -Wextra

all : $(NAME)

$(NAME) : $(OFILES) $(HEADER)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c
	$(C) $(FLAGS) -o $@ -c $^

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
