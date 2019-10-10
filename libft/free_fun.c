/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:40:04 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/23 23:46:05 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_addr(t_room *room)
{
	free(room->addr);
	free(room);
}

void	free_stack_t(t_mem *mem)
{
	t_room	*next;
	t_room	*tofree;

	next = *(mem->temp);
	while (next)
	{
		tofree = next;
		next = next->next;
		free_addr(tofree);
	}
	*(mem->temp) = NULL;
}

void	free_stack(t_mem *mem)
{
	t_room	*next;
	t_room	*tofree;

	free_stack_t(mem);
	next = *(mem->full_stack);
	while (next)
	{
		tofree = next;
		next = next->next;
		free_addr(tofree);
	}
}
