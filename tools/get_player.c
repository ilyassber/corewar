/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:13:51 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/13 12:01:52 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_player	*get_player(t_core *core, int id)
{
	t_hold	*hold;

	hold = *(core->players);
	while (hold)
	{
		if (hold->mem && ((t_player *)(hold->mem))->id == id)
			return ((t_player *)(hold->mem));
		hold = hold->next;
	}
	return (NULL);
}
