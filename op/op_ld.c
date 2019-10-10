/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 08:45:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 20:34:16 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_ld(t_core *core, t_proc *proc)
{
	int	value;

	value = get_arg_value(core, proc, 0, 0);
	if (!is_reg(proc, 1))
		return (0);
	proc->reg[proc->inst->args[1] - 1] = value;
	if (value == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
