/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:27:01 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/03 17:36:37 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	procs_len(t_core *core)
{
	int		i;
	t_hold	*proc;

	i = 0;
	proc = *(core->procs);
	while (proc)
	{
		i++;
		proc = proc->next;
	}
	return (i);
}

int	ctd_check(t_core *core)
{
	t_hold	*proc;
	t_hold	*to_remove;
	int		lives;

	proc = *(core->procs);
	lives = 0;
	while (proc)
	{
		if (((t_proc *)proc->mem)->live == 0)
		{
			to_remove = proc;
			proc = proc->next;
			remove_proc(core->procs, ((t_proc *)to_remove->mem)->id);
		}
		else
		{
			lives += ((t_proc *)proc->mem)->live;
			((t_proc *)proc->mem)->live = 0;
			proc = proc->next;
		}
	}
	return (lives);
}

int	max_check(t_core *core)
{
	int	ctd_c;

	ctd_c = ctd_check(core);
	if (ctd_c >= 21)
	{
		core->ctd -= CYCLE_DELTA;
		core->last_check = core->cycle;
		core->max_check = 0;
	}
	else
	{
		(core->max_check)++;
		if (core->max_check >= 10)
		{
			core->ctd -= CYCLE_DELTA;
			core->last_check = core->cycle;
			core->max_check = 0;
		}
	}
	return (procs_len(core));
}
