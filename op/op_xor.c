/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:48:08 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/16 15:45:49 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_xor(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	res_and;
	int	res_or;

	if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
		return (0);
	arg1 = get_arg_value(core, proc, 0, 0);
	arg2 = get_arg_value(core, proc, 1, 0);
	res_and = arg1 & arg2;
	res_or = arg1 | arg2;
	proc->reg[proc->inst->args[2] - 1] =
		(int)((unsigned int)res_or - (unsigned int)res_and);
	if (proc->reg[proc->inst->args[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
