/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:35:28 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 14:41:50 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_core	*init_core(t_g *g, char **argv, int argc)
{
	t_core	*core;

	core = (t_core *)ft_alloc(g->mem, sizeof(t_core));
	core->area = (char *)ft_alloc(g->mem, sizeof(char) * 4096);
	core->cycle = 0;
	core->ctd = CYCLE_TO_DIE;
	core->check = 0;
	core->last_check = 0;
	core->max_check = 0;
	core->winner = 1;
	core->argv = argv;
	core->argc = argc;
	core->players = (t_hold **)ft_alloc(g->mem, sizeof(t_hold *));
	core->procs = (t_hold **)ft_alloc(g->mem, sizeof(t_hold *));
	core->arg = init_arg(g);
	*(core->players) = NULL;
	*(core->procs) = NULL;
	core->g = g;
	return (core);
}
