/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <bel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:47:17 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/24 14:24:35 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_room	*in_room(void *addr)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
	{
		free(addr);
		return (NULL);
	}
	room->addr = addr;
	room->next = NULL;
	return (room);
}

void	link_to_stack(t_mem *mem, t_room *room, int pass)
{
	if (!room)
		ft_error(mem);
	if (pass == 1)
	{
		if (*(mem->full_stack))
			room->next = *(mem->full_stack);
		*(mem->full_stack) = room;
	}
	else if (pass == 2)
	{
		if (*(mem->temp))
			room->next = *(mem->temp);
		*(mem->temp) = room;
	}
}
