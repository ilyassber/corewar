/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:49:39 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/17 19:12:19 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	print_proc(t_proc *proc)
{
	int	i;

	i = 0;
	if (proc)// && proc->queue == 1 && proc->wait == 1)
	{
		if (proc->queue == 1 && proc->wait == 1)
			ft_putstr(">>>>>>>");
		ft_putstr("##proc_");
		ft_putnbr(proc->id);
		ft_putchar('\n');
		ft_putstr("0x");
		put_char_hex((char)(proc->pointer / 256));
		put_char_hex((char)(proc->pointer % 256));
		ft_putchar(',');
		ft_putnbr(proc->live);
		ft_putchar(',');
		ft_putnbr(proc->inst->inst);
		ft_putchar(',');
		ft_putnbr(proc->wait);
		ft_putchar(',');
		ft_putnbr(proc->inst->skip);
		ft_putchar('\n');
		while (i < 16)
		{
			ft_putnbr(proc->reg[i]);
			ft_putstr(" - ");
			i++;
		}
		ft_putchar('\n');
	}
}

void	print_procs(t_core *core)
{
	t_hold	*next;

	next = *(core->procs);
	ft_putstr("##proc\n");
	ft_putstr("##proc_number\n");
	ft_putnbr(procs_len(core));
	ft_putchar('\n');
	while (next)
	{
		print_proc(next->mem);
		next = next->next;
	}
}
