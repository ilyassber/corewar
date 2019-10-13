/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:50:27 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 15:22:22 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	append_proc(t_hold **procs, t_hold *hold)
{
	t_hold	*next;

	next = *procs;
	while (next && next->next)
		next = next->next;
	if (next)
		next->next = hold;
}

int		remove_proc(t_hold **procs, int id)
{
	t_hold	*keep;
	t_hold	*next;

	next = *procs;
	keep = NULL;
	while (next)
	{
		if (((t_proc *)next->mem)->id == id)
		{
			if (keep && next->next)
				keep->next = next->next;
			else if (keep)
				keep->next = NULL;
			else if (next->next)
				*procs = next->next;
			else
				*procs = NULL;
			return (SUCCESS);
		}
		next = next->next;
	}
	return (ERROR);
}
