/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:31:10 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/08 01:21:05 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	check_proc(t_core *core, t_proc *proc)
{
	t_f	func;

	func = NULL;
	if (proc->queue == 0 && !get_inst(core, proc))
		proc->pointer++;
	else
		proc->wait--;
	if (proc->queue == 1 && proc->wait <= 0)
	{
		get_args_type(proc->inst, *(core->area + proc->pointer + 1));
		get_args(proc->inst, core->area + proc->pointer + 1);
		(proc->inst->skip)++;
		func = g_func[proc->inst->inst];
		func(core, proc);
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
}
