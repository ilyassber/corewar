/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:26:00 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 20:48:18 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_and(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	res;

	arg1 = get_arg_value(core, proc, 0, 0);
	arg2 = get_arg_value(core, proc, 1, 0);
	res = arg1 & arg2;
	if (!is_reg(proc, 2))
		return (0);
	proc->reg[proc->inst->args[2] - 1] = res;
	return (1);
}
