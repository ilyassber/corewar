/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:00:04 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/13 12:10:31 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_live(t_core *core, t_proc *proc)
{
	t_player	*player;
	int			id;

	id = proc->inst->args[0];
	if (id < 0)
		id = id * -1;
	player = get_player(core, id);
	if (player)
	{
		(proc->live)++;
		(player->alive)++;
		(player->lives)++;
		return (1);
	}
	return (0);
}
