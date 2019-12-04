/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:42:45 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 14:50:57 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	init_lives(t_hold **players)
{
	t_hold		*hold;
	t_player	*player;

	hold = *players;
	while (hold)
	{
		player = (t_player *)(hold->mem);
		player->lives = 0;
		hold = hold->next;
	}
}
