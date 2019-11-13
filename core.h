/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:24:13 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/13 17:16:33 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdio.h>
# include "libft/libft.h"
# include "op.h"
# include <stdio.h>

# define SUCCESS			1
# define ERROR				0
# define UNEXPECTED_ARG		-10
# define UNEXPECTED_FLAG	-11
# define BAD_ORDER			-12
# define UNVALID_ARG		-13
# define UNVALID_PATH		-14

# define EST ft_putstr("esti!!\n");
# define RUN ft_putstr("RUUN RUUN!!\n");

typedef struct		s_proc	t_proc;
typedef struct		s_core	t_core;

typedef				int (*t_f)(t_core *, t_proc *);

typedef struct		s_hold
{
	void			*mem;
	struct s_hold	*next;
}					t_hold;

typedef struct		s_arg
{
	int				dump;
	int				n;
	int				order;
	t_hold			**paths;
}					t_arg;

typedef struct		s_player
{
	int				id;
	char			*code;
	char			*name;
	char			*comment;
	char			*exe;
	int				size;
	int				alive;
	int				lives;
	int				win;
}					t_player;

typedef struct		s_inst
{
	int				inst;
	char			args_type[3];
	int				args[3];
	int				skip;
}					t_inst;

typedef struct		s_proc
{
	int				id;
	int				pointer;
	int				carry;
	int				reg[16];
	int				live;
	int				queue;
	int				wait;
	t_inst			*inst;
}					t_proc;

typedef struct		s_core
{
	char			*area;
	int				cycle;
	int				ctd;
	int				last_check;
	int				max_check;
	int				check;
	char			**argv;
	int				argc;
	t_arg			*arg;
	t_hold			**players;
	t_hold			**procs;
	t_g				*g;
}					t_core;

t_op				g_op_tab[17];
t_f					g_func[17];
t_player			*init_player(t_g *g, char *code, int id);
t_core				*init_core(t_g *g, char **argv, int argc);
t_inst				*init_inst(t_g *g);
t_proc				*init_proc(t_g *g);
t_arg				*init_arg(t_g *g);
void				init_inst_params(t_inst *inst);
int					is_op(char *mem);
int					to_next_inst(char *mem, t_inst *inst);
int					get_args_type(t_inst *inst, char c);
int					get_args(t_inst *inst, char *mem);
void				parser_loop(t_core *core);
int					read_value(char *mem, int n);
t_player			*get_player(t_core *core, int id);
int					is_reg(t_proc *proc, int arg);
int					get_value(t_core *core, t_proc *proc, int step, int l);
void				set_value(t_core *core, t_proc *proc, int step, int value);
int					get_arg_value(t_core *core, t_proc *proc, int n, int l);
void				duplicate_proc(t_proc *old, t_proc *new);
t_hold				*holding(t_g *g, void *mem);
void				append_to_hold(t_hold **stack, t_hold *holder);
int					get_inst(t_core *core, t_proc *proc);

int					op_add(t_core *core, t_proc *proc);
int					op_aff(t_core *core, t_proc *proc);
int					op_and(t_core *core, t_proc *proc);
int					op_fork(t_core *core, t_proc *proc);
int					op_ld(t_core *core, t_proc *proc);
int					op_ldi(t_core *core, t_proc *proc);
int					op_lfork(t_core *core, t_proc *proc);
int					op_live(t_core *core, t_proc *proc);
int					op_lld(t_core *core, t_proc *proc);
int					op_lldi(t_core *core, t_proc *proc);
int					op_or(t_core *core, t_proc *proc);
int					op_st(t_core *core, t_proc *proc);
int					op_sti(t_core *core, t_proc *proc);
int					op_sub(t_core *core, t_proc *proc);
int					op_xor(t_core *core, t_proc *proc);
int					op_zjmp(t_core *core, t_proc *proc);

int					check_players(t_arg *arg, char **argv, int argc);
int					get_dump(char **argv, int argc);
int					check_flags(char **argv, int argc);
int					check_order(t_arg *arg, char **argv, int argc);
char				*get_arg_by_order(char **argv, int argc, int n);
int					jump_flags(char **argv, int argc);
void				on_error(t_g *g, int code);
void				parse_args(t_core *core, char **argv, int argc);
void				extract_players(t_core *core);
void				append_proc(t_hold **procs, t_hold *hold);
int					remove_proc(t_hold **procs, t_proc *proc);
void				init_procs(t_core *core);
int					ctd_check(t_core *core);
int					max_check(t_core *core);
int					procs_len(t_core *core);
void				check_procs(t_core *core);
void				check_proc(t_core *core, t_proc *proc);
void				init_engine(t_core *core);
int					engine(t_core *core);
void				init_area(t_core *core);
void				dump(t_core *core);
void				print_proc(t_proc *proc);
void				print_procs(t_core *core);
void				intro_players(t_core *core);

#endif
