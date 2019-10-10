/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:23:08 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 20:46:50 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_add(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	sum;

	if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
		return (0);
	arg1 = get_arg_value(core, proc, 0, 0);
	arg2 = get_arg_value(core, proc, 1, 0);
	sum = arg1 + arg2;
	if (sum == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[proc->inst->args[2] - 1] = sum;
	return (1);
}
