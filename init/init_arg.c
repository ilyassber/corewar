/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 07:54:54 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 11:40:44 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_arg	*init_arg(t_g *g)
{
	t_arg	*arg;

	arg = (t_arg *)ft_alloc(g->mem, sizeof(t_arg));
	arg->dump = -1;
	arg->n = 0;
	arg->order = 0;
	arg->paths = (t_hold **)ft_alloc(g->mem, sizeof(t_hold *));
	*(arg->paths) = NULL;
	return (arg);
}
