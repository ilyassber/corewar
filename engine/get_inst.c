/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:25:04 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/14 21:27:28 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	get_inst(t_core *core, t_proc *proc)
{
	init_inst_params(proc->inst);
	if (is_op(core->area + proc->pointer))
	{
		proc->inst->inst = *(core->area + proc->pointer);
		get_args_type(proc->inst, *(core->area + proc->pointer + 1));
		get_args(proc->inst, core->area + proc->pointer + 1);
		(proc->inst->skip)++;
		proc->wait = g_op_tab[proc->inst->inst - 1].cycles;
		proc->queue = 1;
		return (SUCCESS);
	}
	(proc->inst->skip)++;
	return (ERROR);
}
