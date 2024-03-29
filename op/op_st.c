/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:58:48 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/15 13:40:35 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_st(t_core *core, t_proc *proc)
{
	int	value;

	if (!(is_reg(proc, 0) && is_reg(proc, 1)))
		return (0);
	value = proc->reg[proc->inst->args[0] - 1];
	if (proc->inst->args_type[1] == 1)
		proc->reg[proc->inst->args[1] - 1] = value;
	else
		set_value(core, proc, (proc->inst->args[1] % IDX_MOD), value);
	return (1);
}
