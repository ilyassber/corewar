/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:31:10 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/07 07:16:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	check_proc(t_core *core, t_proc *proc)
{
	t_f	func;

	func = NULL;
	if (proc->wait > 0)
		proc->wait--;
	else
	{
		if (proc->queue == 1)
		{
			//execute_inst(proc);
			func = g_func[proc->inst->inst];
			func(core, proc);
			proc->queue = 0;
		}
		else
			get_inst(core, proc);
	}
}

int		check_procs(t_core *core)
{
	t_hold	*hold;
	int		i;

	i = 0;
	hold = *(core->procs);
	while (hold)
	{
		i++;
		if (hold->mem)
			check_proc(core, (t_proc *)(hold->mem));
		hold = hold->next;
	}
	return (i);
}
