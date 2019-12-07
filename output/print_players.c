/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:34:28 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 13:44:57 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

static void	print_player(t_player *player, int n)
{
	int	pointer;

	pointer = (MEM_SIZE / n) * (player->id - 1);
	ft_putstr(player->name);
	ft_putchar('\n');
	ft_putstr(player->comment);
	ft_putchar('\n');
	ft_putnbr(pointer);
	ft_putchar('-');
	ft_putnbr(pointer + player->size);
	ft_putchar('\n');
}

void	print_players(t_core *core)
{
	t_player	*player;
	int			i;

	i = 1;
	if (core->arg->n > 0)
	{
		ft_putstr("##player-");
		ft_putnbr(core->arg->n);
		ft_putchar('\n');
		while (i <= core->arg->n)
		{
			player = get_player(core, i);
			print_player(player, core->arg->n);
			i++;
		}
	}
}
