/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_procs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:58:25 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 23:18:00 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	init_procs(t_core *core)
{
	t_proc	*proc;
	int		i;

	i = 1;
	while (i <= core->arg->n)
	{
		proc = init_proc(core->g);
		proc->reg[0] = i;
		proc->inst = init_inst(core->g);
		proc->pointer = (MEM_SIZE / core->arg->n) * (i - 1);
		append_proc(core->procs, holding(core->g, (void *)proc));
		i++;
	}
}
