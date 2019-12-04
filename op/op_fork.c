/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:10:35 by iberchid          #+#    #+#             */
/*   Updated: 2019/12/04 13:28:23 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	duplicate_proc(t_proc *old, t_proc *new)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		new->reg[i] = old->reg[i];
		i++;
	}
	new->carry = old->carry;
	new->live = old->live;
	new->creator_id = old->creator_id;
}

int		op_fork(t_core *core, t_proc *proc)
{
	t_proc	*new;

	new = init_proc(core->g);
	new->pointer = (proc->pointer + (proc->inst->args[0] % IDX_MOD)) % MEM_SIZE;
	if (new->pointer < 0)
		new->pointer = new->pointer + MEM_SIZE;
	new->inst = init_inst(core->g);
	duplicate_proc(proc, new);
	append_to_hold(core->procs, holding(core->g, (void *)new));
	return (1);
}
