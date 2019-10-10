/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:24:13 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/10 12:57:43 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "libft/libft.h"
# include "op.h"
# include <stdio.h>

# define EST ft_putstr("esti!!\n");

typedef struct		s_proc	t_proc;
typedef struct		s_core	t_core;

typedef				int (*t_f)(t_core *, t_proc *);

typedef struct		s_hold
{
	void			*mem;
	struct s_hold	*next;
}					t_hold;

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
	int				pointer;
	int				carry;
	int				reg[16];
	int				last_live;
	int				queue;
	int				wait;
	t_inst			*inst;
}					t_proc;

typedef struct		s_core
{
	char			*area;
	int				cycle;
	int				ctd;
	int				check;
	int				p_nbr;
	t_hold			**players;
	t_hold			**procs;
	t_g				*g;
}					t_core;

t_op				g_op_tab[17];
t_f					g_func[17];
t_player			*init_player(t_g *g, char *code, int id);
t_core				*init_core(t_g *g);
t_inst				*init_inst(t_g *g);
t_proc				*init_proc(t_g *g);
void				init_inst_params(t_inst *inst);
int					is_op(char *mem);
int					to_next_inst(char *mem, t_inst *inst);
int					get_args_type(t_inst *inst, char c);
int					get_args(t_inst *inst, char *mem);
void				parser_loop(t_core *core);
int					read_value(char *mem, int n);
t_player			*get_player(t_core *core, int id);
int					is_reg(t_proc *proc, int arg);
int					get_value(t_core *core, t_proc *proc, int step);
void				set_value(t_core *core, t_proc *proc, int step, int value);
int					get_arg_value(t_core *core, t_proc *proc, int n);
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

#endif
