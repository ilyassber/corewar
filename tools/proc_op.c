/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:50:27 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/13 17:46:40 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	append_proc(t_hold **procs, t_hold *hold)
{
	t_hold	*next;

	next = *procs;
	hold->next = next;
	*procs = hold;
}

int		remove_proc(t_hold **procs, t_proc *proc)
{
	t_hold	*keep;
	t_hold	*next;

	next = *procs;
	keep = NULL;
	while (next)
	{
		if (((t_proc *)next->mem) == proc)
		{
			if (keep)
				keep->next = next->next;
			else if (next->next)
				*procs = next->next;
			else
				*procs = NULL;
			return (SUCCESS);
		}
		keep = next;
		next = next->next;
	}
	return (ERROR);
}
