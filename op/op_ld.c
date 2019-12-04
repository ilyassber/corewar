/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 08:45:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/21 11:09:37 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_ld(t_core *core, t_proc *proc)
{
	int	value;

	value = get_arg_value(core, proc, 0, 0);
	proc->reg[proc->inst->args[1] - 1] = value;
	if (value == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
