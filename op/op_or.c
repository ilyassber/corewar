/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:43:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/21 11:10:18 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_or(t_core *core, t_proc *proc)
{
	int	arg1;
	int	arg2;
	int	res;

	arg1 = get_arg_value(core, proc, 0, 0);
	arg2 = get_arg_value(core, proc, 1, 0);
	res = arg1 | arg2;
	proc->reg[proc->inst->args[2] - 1] = res;
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
