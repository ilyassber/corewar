/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:51:17 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/07 20:58:14 by iberchid         ###   ########.fr       */
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
	while (proc->pointer < 1024)
	{
		if (get_inst(core, proc))
			printf("op : %d\t- Encoding : %d - Types : %d, %d, %d - ARGS : %d\t, %d\t, %d\n",
					proc->inst->inst,
					g_op_tab[proc->inst->inst - 1].encoding,
					proc->inst->args_type[0],
					proc->inst->args_type[1],
					proc->inst->args_type[2],
					proc->inst->args[0],
					proc->inst->args[1],
					proc->inst->args[2]);
		proc->pointer += proc->inst->skip;
	}
}
