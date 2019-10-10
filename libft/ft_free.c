/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:43:41 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/23 21:35:55 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_mem *mem, void *addr)
{
	t_room	*prev;
	t_room	*next;

	prev = NULL;
	next = *(mem->full_stack);
	while (next && next->addr != addr)
	{
		prev = next;
		next = next->next;
	}
	if (next && prev && addr)
	{
		prev->next = NULL;
		if (next->next)
			prev->next = next->next;
		free_addr(next);
	}
	else if (next)
	{
		*(mem->full_stack) = NULL;
		if (next->next)
			*(mem->full_stack) = next->next;
		free_addr(next);
	}
}

void	ft_free_t(t_mem *mem, void *addr)
{
	t_room	*prev;
	t_room	*next;

	prev = NULL;
	next = *(mem->temp);
	while (next && next->addr != addr)
	{
		prev = next;
		next = next->next;
	}
	if (next && prev && addr)
	{
		prev->next = NULL;
		if (next->next)
			prev->next = next->next;
		free_addr(next);
	}
	else if (next)
	{
		*(mem->temp) = NULL;
		if (next->next)
			*(mem->temp) = next->next;
		free_addr(next);
	}
}
