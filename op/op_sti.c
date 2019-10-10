/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:44:39 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 21:07:10 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_sti(t_core *core, t_proc *proc)
{
	int	value;
	int	arg2;
	int	arg3;

	if (!(is_reg(proc, 0) && is_reg(proc, 1) && is_reg(proc, 2)))
		return (0);
	value = proc->inst->args[0];
	arg2 = get_arg_value(core, proc, 1, 0);
	arg3 = get_arg_value(core, proc, 2, 0);
	set_value(core, proc, ((arg2 + arg3) % IDX_MOD), value);
	return (1);
}
