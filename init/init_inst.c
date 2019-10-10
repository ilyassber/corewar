/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:06:14 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/24 17:55:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	init_inst_params(t_inst *inst)
{
	inst->inst = 0;
	inst->skip = 0;
	inst->args_type[0] = 0;
	inst->args_type[1] = 0;
	inst->args_type[2] = 0;
	inst->args[0] = 0;
	inst->args[1] = 0;
	inst->args[2] = 0;
}

t_inst	*init_inst(t_g *g)
{
	t_inst	*inst;

	inst = (t_inst *)ft_alloc(g->mem, sizeof(t_inst));
	init_inst_params(inst);
	return (inst);
}
