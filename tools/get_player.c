/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:13:51 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/04 22:54:02 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

t_player	*get_player(t_core *core, int id)
{
	t_hold	*hold;
	int		i;

	i = 1;
	hold = *(core->players);
	while (hold && hold->next && i < id)
	{
		hold = hold->next;
		i++;
	}
	if (i == id && hold && hold->mem)
		return ((t_player *)(hold->mem));
	return (NULL);
}
