/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:51:17 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/13 09:50:48 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	parser_loop(t_core *core)
{
	int		i;
	t_proc	*proc;

	i = 0;
	proc = init_proc(core->g);
	proc->inst = init_inst(core->g);
	while (proc->pointer < 4096)
	{
		if (get_inst(core, proc))
		{
			get_args_type(proc->inst, *(core->area + proc->pointer + 1));
			get_args(proc->inst, core->area + proc->pointer + 1);
			(proc->inst->skip)++;
			printf("op : %d\t- Encoding : %d - Types : %d, %d, %d - ARGS : %d\t, %d\t, %d\n",
					proc->inst->inst,
					g_op_tab[proc->inst->inst - 1].encoding,
					proc->inst->args_type[0],
					proc->inst->args_type[1],
					proc->inst->args_type[2],
					proc->inst->args[0],
					proc->inst->args[1],
					proc->inst->args[2]);
		}
		else
			proc->pointer++;
		proc->pointer += proc->inst->skip;
	}
}
