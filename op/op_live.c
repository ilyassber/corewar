/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:00:04 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 14:40:40 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_live(t_core *core, t_proc *proc)
{
	t_player	*player;
	int			id;

	id = proc->inst->args[0];
	id = id * -1;
	(proc->live)++;
	player = get_player(core, id);
	if (player)
	{
		/*
		ft_putstr("Player ");
		ft_putnbr(player->id);
		ft_putstr(" is said to be alive\n");
		*/
		player->alive = core->cycle;
		core->winner = id;
		(player->lives)++;
		return (1);
	}
	return (0);
}
