/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:02:05 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 15:20:53 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_sub(t_core *core, t_proc *proc)
{
	int	sub;

	if (core)
	{
		if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
			return (0);
		sub = proc->reg[proc->inst->args[0] - 1] -
			proc->reg[proc->inst->args[1] - 1];
		if (sub == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
		proc->reg[proc->inst->args[2] - 1] = sub;
		return (1);
	}
	return (0);
}
