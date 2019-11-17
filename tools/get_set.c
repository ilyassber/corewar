/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 09:27:06 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/15 12:17:58 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	get_value(t_core *core, t_proc *proc, int step, int l)
{
	int				position;
	unsigned int	value;
	int				i;

	i = 0;
	value = 0;
	if (!l)
		step = step % IDX_MOD;
	position = (proc->pointer + step) % MEM_SIZE;
	if (position < 0)
		position = position + MEM_SIZE;
	/*
	ft_putstr("******* get *******\n");
	ft_putnbr(proc->pointer);
	ft_putstr(" - ");
	ft_putnbr(step);
	ft_putstr(" - ");
	ft_putnbr(position);
	ft_putstr(" - ");
	*/
	while (i < 4)
	{
		/*
		ft_putnbr((int)((unsigned char)*(core->area + ((position + i) % MEM_SIZE))));
		if (i < 3)
			ft_putchar('*');
		*/
		value = value * 256;
		value = value + (unsigned char)*(core->area + ((position + i) % MEM_SIZE));
		i++;
	}
	/*
	ft_putstr(" - ");
	ft_putnbr((int)value);
	ft_putstr("\n*******************\n");
	*/
	return ((int)value);
}

void	set_value(t_core *core, t_proc *proc, int step, int value)
{
	int				i;
	int				position;
	unsigned int	u_value;

	u_value = (unsigned int)value;
	i = 4;
	position = (proc->pointer + step) % MEM_SIZE;
	if (position < 0)
		position = position + MEM_SIZE;
	while (i-- > 0)
	{
		core->area[(position + i) % MEM_SIZE] = u_value % 256;
		u_value = u_value - (u_value % 256);
		u_value = u_value / 256;
	}
}

int		get_arg_value(t_core *core, t_proc *proc, int n, int l)
{
	if (proc->inst->args_type[n] == 1)
		return (proc->reg[proc->inst->args[n] - 1]);
	else if (proc->inst->args_type[n] == 2)
		return (proc->inst->args[n]);
	else if (proc->inst->args_type[n] == 4)
		return (get_value(core, proc, proc->inst->args[n], l));
	return (0);
}
