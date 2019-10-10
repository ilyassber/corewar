/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:57:34 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 21:27:50 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_ldi(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;

	if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
		return (0);
	arg1 = get_arg_value(core, proc, 0, 0);
	arg2 = get_arg_value(core, proc, 1, 0);
	proc->reg[proc->inst->args[2]] = get_value(core, proc, (arg1 + arg2), 0);
	return (1);
}
