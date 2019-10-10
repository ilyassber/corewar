/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:35:28 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/05 17:16:29 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_core	*init_core(t_g *g)
{
	t_core	*core;

	core = (t_core *)ft_alloc(g->mem, sizeof(t_core));
	core->cycle = 0;
	core->ctd = CYCLE_TO_DIE;
	core->check = 0;
	core->p_nbr = 0;
	core->players = (t_hold **)ft_alloc(g->mem, sizeof(t_hold *));
	core->procs = (t_hold **)ft_alloc(g->mem, sizeof(t_hold *));
	*(core->players) = NULL;
	*(core->procs) = NULL;
	core->g = g;
	return (core);
}
