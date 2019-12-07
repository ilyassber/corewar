/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:28:13 by iberchid          #+#    #+#             */
/*   Updated: 2019/12/04 13:33:24 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	players_info(t_core *core)
{
	t_player	*player;
	int			i;

	i = 1;
	ft_putstr("##player\n");
	while (i <= core->arg->n)
	{
		player = get_player(core, i);
		ft_putnbr(player->alive);
		ft_putchar(',');
		ft_putnbr(player->lives);
		ft_putchar('\n');
		i++;
	}
}
