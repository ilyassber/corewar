/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:50:27 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/17 21:40:59 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

/*
void	append_proc(t_hold **procs, t_hold *hold)
{
	t_hold	*next;

	next = *procs;
	hold->next = next;
	*procs = hold;
}
*/

int		remove_proc(t_hold **procs, t_hold *proc)
{
	t_hold	*keep;

	/*
	ft_putstr("remove proc - lives : ");
	ft_putnbr(((t_proc *)(proc->mem))->live);
	ft_putstr("\n");
	*/
	keep = proc->prec;
	if (keep)
		keep->next = proc->next;
	else if (proc->next)
	{
		*procs = proc->next;
		(*procs)->prec = NULL;
	}
	else
		*procs = NULL;
	return (SUCCESS);
}
