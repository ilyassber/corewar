/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:20:34 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/05 17:42:47 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	init_area(t_core *core)
{
	int		div;
	int		i;
	t_hold	*hold;

	div = MEM_SIZE / core->p_nbr;
	i = 0;
	while (i < 682)
	{
		hold = *(core->players);
		while (hold)
		{
			core->area[(div * ((t_player *)(hold->mem)->id - 1)) + i] =
				(t_player *)(hold->mem)->exe[i];
			hold = hold->next;
		}
		i++;
	}
}
