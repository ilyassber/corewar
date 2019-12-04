/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:37:11 by iberchid          #+#    #+#             */
/*   Updated: 2019/12/04 22:01:51 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_player	*init_player(t_g *g, char *code, int id)
{
	t_player	*player;

	player = (t_player *)ft_alloc(g->mem, sizeof(t_player));
	player->id = id;
	player->code = code;
	player->name = cut_until(g, code + 4, 128, 1);
	player->size = read_value(code + 136, 4);
	if (player->size > CHAMP_MAX_SIZE)
		on_error(g, OVER_MAX_SIZE);
	player->comment = cut_until(g, code + 140, 2048, 1);
	player->exe = cut_until(g, code + 2192, 1024, 0);
	player->alive = 0;
	player->lives = 0;
	player->win = 0;
	return (player);
}
