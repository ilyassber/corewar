/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:04:15 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/12 10:33:11 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	get_op_args_type(int op, int n)
{
	if (n == 1)
		return (g_op_tab[op - 1].args.arg1);
	else if (n == 2)
		return (g_op_tab[op - 1].args.arg2);
	else if (n == 3)
		return (g_op_tab[op - 1].args.arg3);
	else
		return (0);
}

int	get_args_type(t_inst *inst, char c)
{
	int		i;

	i = 0;
	if (!(g_op_tab[inst->inst - 1].encoding))
	{
		inst->args_type[0] = g_op_tab[inst->inst - 1].args.arg1;
		inst->args_type[1] = g_op_tab[inst->inst - 1].args.arg2;
		inst->args_type[2] = g_op_tab[inst->inst - 1].args.arg3;
		return (0);
	}
	(inst->skip)++;
	while (i < 3)
	{
		c = c >> 2;
		if ((c & 3) == 3)
			inst->args_type[2 - i] = T_IND;
		else if ((c & 2) == 2)
			inst->args_type[2 - i] = T_DIR;
		else if ((c & 1) == 1)
			inst->args_type[2 - i] = T_REG;
		i++;
	}
	return (1);
}

int	get_args(t_inst *inst, char *mem)
{
	int	i;
	int	hold;

	i = 0;
	while (++i <= 3)
	{
		hold = 0;
		if (inst->args_type[i - 1])
		{
			if ((inst->args_type[i - 1] == 2) &&
					g_op_tab[inst->inst - 1].carry == 0 && (hold = 4))
				inst->args[i - 1] = read_value(mem + inst->skip, 4);
			else if ((inst->args_type[i - 1] == 2) &&
					g_op_tab[inst->inst - 1].carry == 1 && (hold = 2))
				inst->args[i - 1] = read_value(mem + inst->skip, 2);
			else if (((inst->args_type[i - 1] == 4)) && (hold = 2))
				inst->args[i - 1] = read_value(mem + inst->skip, 2);
			else if (((inst->args_type[i - 1] == 1)) && (hold = 1))
				inst->args[i - 1] = read_value(mem + inst->skip, 1);
		}
		inst->skip += hold;
	}
	return (inst->skip);
}
