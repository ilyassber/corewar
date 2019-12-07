/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:52:04 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 15:00:54 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	print_winner(t_core *core)
{
	t_player	*player;

	player = get_player(core, core->winner);
	if (core->arg->v == 1)
		ft_putstr("##winner\n");
	ft_putstr("Contestant ");
	ft_putnbr(player->id);
	ft_putstr(", \"");
	ft_putstr(player->name);
	ft_putstr("\", has won !\n");
}
