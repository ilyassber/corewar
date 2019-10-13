/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:48:06 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 12:45:16 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_proc	*init_proc(t_g *g)
{
	t_proc	*proc;
	int		i;

	i = 0;
	proc = (t_proc *)ft_alloc(g->mem, sizeof(t_proc));
	proc->pointer = 0;
	proc->carry = 0;
	proc->last_live = 0;
	proc->queue = 0;
	proc->wait = 0;
	proc->inst = NULL;
	while (i < 16)
	{
		proc->reg[i] = 0;
		i++;
	}
	return (proc);
}
