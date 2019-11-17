/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:48:48 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/17 19:42:09 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	print_reg(t_proc *proc, int i)
{
	ft_putstr("REG_");
	ft_putnbr(proc->inst->args[i]);
	ft_putstr(" : ");
	ft_putnbr(proc->reg[proc->inst->args[i] - 1]);
	ft_putchar('\n');
}

void	print_dir(t_proc *proc, int i)
{
	ft_putstr("DIR : ");
	ft_putnbr(proc->inst->args[i]);
	ft_putchar('\n');
}

void	print_ind(t_core *core, t_proc *proc, int i)
{
	int	m;

	m = proc->inst->inst;
	ft_putstr("IND_");
	ft_putnbr(proc->inst->args[i]);
	ft_putstr(" : ");
	if (m == 13 || m == 14 || m == 15)
		ft_putnbr(get_value(core, proc, proc->inst->args[i], 1));
	else
		ft_putnbr(get_value(core, proc, proc->inst->args[i], 0));
	ft_putchar('\n');
}

void	print_inst(t_core *core, t_proc *proc)
{
	int		i;

	i = 0;
	ft_putstr(g_op_tab[proc->inst->inst - 1].op_name);
	ft_putstr(" _ 0x");
	put_char_hex((char)(proc->pointer / 256));
	put_char_hex((char)(proc->pointer % 256));
	ft_putstr(" >> ");
	ft_putnbr(proc->inst->args_type[0]);
	ft_putstr(", ");
	ft_putnbr(proc->inst->args_type[1]);
	ft_putstr(", ");
	ft_putnbr(proc->inst->args_type[2]);
	ft_putchar('\n');
	while (proc->inst->args_type[i] && i < 3)
	{
		if (proc->inst->args_type[i] == 1)
			print_reg(proc, i);
		else if (proc->inst->args_type[i] == 2)
			print_dir(proc, i);
		else if (proc->inst->args_type[i] == 4)
			print_ind(core, proc, i);
		i++;
	}
}
