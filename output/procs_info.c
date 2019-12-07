/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:59:37 by iberchid          #+#    #+#             */
/*   Updated: 2019/12/04 13:31:37 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

static void	proc_info(t_proc *proc)
{
	ft_putnbr(proc->pointer);
	ft_putchar(',');
	ft_putnbr(proc->creator_id);
	ft_putchar(',');
	if (proc->inst->update == -1)
		ft_putnbr(0);
	else
	{
		ft_putnbr(1);
		ft_putchar(',');
		ft_putnbr(proc->inst->update);
		ft_putchar('-');
		ft_putnbr(proc->inst->update + 4);
	}
	ft_putchar('\n');
}

void	procs_info(t_core *core)
{
	t_hold	*hold;
	t_proc	*proc;

	hold = *(core->procs);
	if (hold)
	{
		ft_putstr("##proc-number\n");
		ft_putnbr(procs_len(core));
		ft_putchar('\n');
		while (hold)
		{
			proc = (t_proc *)(hold->mem);
			proc_info(proc);
			hold = hold->next;
		}
	}
}
