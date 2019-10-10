/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:18:59 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 21:27:56 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_lldi(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;

	if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
		return (0);
	arg1 = get_arg_value(core, proc, 0, 1);
	arg2 = get_arg_value(core, proc, 1, 1);
	proc->reg[proc->inst->args[2]] = get_value(core, proc, (arg1 + arg2), 1);
	return (1);
}
