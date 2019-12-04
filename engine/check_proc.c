/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:31:10 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 19:07:02 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int		check_args(t_inst *inst)
{
	if (((inst->args_type[0] & g_op_tab[inst->inst - 1].args.arg1) !=
			inst->args_type[0]) || (g_op_tab[inst->inst - 1].args.arg1 &&
				!(inst->args_type[0])))
		return (0);
	if (((inst->args_type[1] & g_op_tab[inst->inst - 1].args.arg2) !=
			inst->args_type[1]) || (g_op_tab[inst->inst - 1].args.arg2 &&
				!(inst->args_type[1])))
		return (0);
	if (((inst->args_type[2] & g_op_tab[inst->inst - 1].args.arg3) !=
			inst->args_type[2]) || (g_op_tab[inst->inst - 1].args.arg3 &&
				!(inst->args_type[2])))
		return (0);
	return (1);
}

void	check_proc(t_core *core, t_proc *proc)
{
	t_f	func;

	func = NULL;
	if (proc->queue == 0 && !get_inst(core, proc))
		proc->pointer = (proc->pointer + 1) % MEM_SIZE;
	else
		proc->wait--;
	if (proc->queue == 1 && proc->wait <= 0)
	{
		get_args_type(proc->inst, *(core->area +
					((proc->pointer + 1) % MEM_SIZE)));
		get_args(proc->inst, core->area, ((proc->pointer + 1) % MEM_SIZE));
		(proc->inst->skip)++;
		func = g_func[proc->inst->inst];
		if (check_args(proc->inst) && is_reg(proc, 0) && is_reg(proc, 1)
				&& is_reg(proc, 2))
		{
			//ft_putstr(g_op_tab[proc->inst->inst - 1].op_name);
			//ft_putchar('\n');
			//print_inst(core, proc);
			func(core, proc);
		}
		proc->queue = 0;
		if (proc->inst->inst != 9)
			proc->pointer = (proc->pointer + proc->inst->skip) % MEM_SIZE;
	}
}

void	check_procs(t_core *core)
{
	t_hold	*hold;

	hold = *(core->procs);
	while (hold)
	{
		if (hold->mem)
			check_proc(core, (t_proc *)(hold->mem));
		hold = hold->next;
	}
	loop_out(core);
}
