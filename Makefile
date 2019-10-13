# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-bouz <bel-bouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 00:09:47 by bel-bouz          #+#    #+#              #
#    Updated: 2019/10/13 23:20:53 by iberchid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft
LFT = libft/libft.a
C_F =	core.c \
		op.c \
		init/init_core.c \
		init/init_player.c \
		init/init_proc.c \
		init/init_inst.c \
		init/init_arg.c \
		parse/get_args.c \
		parse/next_inst.c \
		parse/parse_check.c \
		parse/parser.c \
		parse/read_value.c \
		parse/parse_args.c \
		tools/get_player.c \
		tools/is_reg.c \
		tools/proc_op.c \
		tools/to_hold.c \
		tools/get_set.c \
		engine/get_inst.c \
		engine/check_proc.c \
		engine/extract_players.c \
		engine/init_procs.c \
		engine/engine.c \
		error/on_error.c \
		op/op_add.c \
		op/op_aff.c \
		op/op_and.c \
		op/op_fork.c \
		op/op_ld.c \
		op/op_ldi.c \
		op/op_lfork.c \
		op/op_live.c \
		op/op_lld.c \
		op/op_lldi.c \
		op/op_or.c \
		op/op_st.c \
		op/op_sti.c \
		op/op_sub.c \
		op/op_xor.c \
		op/op_zjmp.c
O_F = $(C_F:.c=.o)
HEADER = core.h
C = gcc
FLAGS = -Wall -Werror -Wextra
NAME = core
LIB = -L./libft -lft

all: libf $(NAME)

$(NAME): $(LFT) $(O_F) $(HEADER)
	$(C) -o $(NAME) $(O_F) $(LIB)

libf:
	make -C $(LIBFT)

%.o: %.c
	$(C) $(FLAGS) -o $@ -c $^

clean:
	make clean -C $(LIBFT)
	rm -rf $(O_F)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
