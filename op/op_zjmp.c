/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:06:26 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/06 22:36:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_zjmp(t_core *core, t_proc *proc)
{
	int	step;

	if (core)
	{
		step = proc->inst->args[0];
		if (proc->carry == 1)
		{
			proc->pointer = (proc->pointer + (step % IDX_MOD)) % MEM_SIZE;
			if (proc->pointer < 0)
				proc->pointer = proc->pointer + MEM_SIZE;
		}
		else
			proc->pointer = (proc->pointer + proc->inst->skip) % MEM_SIZE;
		return (1);
	}
	return (0);
}
