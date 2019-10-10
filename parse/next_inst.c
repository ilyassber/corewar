/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:06:59 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/21 21:45:15 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	to_next_inst(char *mem, t_inst *inst)
{
	int	i;

	i = g_op_tab[inst->inst].encoding
		+ inst->args_type[0]
		+ inst->args_type[1]
		+ inst->args_type[2]
		+ 1;
	while (!(is_op(mem + i)))
		i++;
	return (i);
}
