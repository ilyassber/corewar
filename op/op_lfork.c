/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:28:22 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 21:40:10 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_lfork(t_core *core, t_proc *proc)
{
	t_proc	*new;

	new = init_proc(core->g);
	new->pointer = (proc->pointer + proc->inst->args[0]) % MEM_SIZE;
	if (new->pointer < 0)
		new->pointer = new->pointer + MEM_SIZE;
	new->inst = init_inst(core->g);
	duplicate_proc(proc, new);
	append_to_hold(core->procs, holding(core->g, (void *)new));
	return (1);
}
