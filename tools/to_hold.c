/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:41:05 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 11:00:10 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_hold	*holding(t_g *g, void *mem)
{
	t_hold	*hold;

	hold = (t_hold *)ft_alloc(g->mem, sizeof(t_hold));
	hold->mem = mem;
	hold->next = NULL;
	return (hold);
}

void	append_to_hold(t_hold **stack, t_hold *holder)
{
	if (stack && *stack)
		holder->next = *stack;
	if (stack)
		*stack = holder
}
