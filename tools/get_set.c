/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 09:27:06 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 21:04:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	get_value(t_core *core, t_proc *proc, int step, int l)
{
	int	position;
	int	value;
	int	i;

	i = 3;
	value = 0;
	if (!l)
		step = step % IDX_MOD;
	position = (proc->pointer + step) % MEM_SIZE;
	if (position < 0)
		position = position + MEM_SIZE;
	while (i >= 0)
	{
		value = value * 256;
		value = value + (int)(*(area + ((position + i) % MEM_SIZE)));
		i--;
	}
	return (value);
}

void	set_value(t_core *core, t_proc *proc, int step, int value)
{
	int	i;
	int	position;

	i = 0;
	position = (proc->pointer + step) % MEM_SIZE;
	if (position < 0)
		position = position + MEM_SIZE;
	while (i < 4)
	{
		core->area[(position + i) % MEM_SIZE] = value % 256;
		value = value - (value % 256);
		value = value / 256;
		i++;
	}
}

int		get_arg_value(t_core *core, t_proc *proc, int n, int l)
{
	if (proc->inst->args_type[n] == 1)
		return (proc->reg[proc->inst->args[n] - 1]);
	else if (proc->inst->args_type[n] == 2)
		return (proc->inst->args[n]);
	else if (proc->inst->args_type[n] == 4)
		return (get_value(core, proc, proc->inst->args[n], l));
}
