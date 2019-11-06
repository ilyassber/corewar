/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <bel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:06:43 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/06 12:07:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_mem(t_g *g)
{
	if (!(g->mem->full_stack = (t_room **)malloc(sizeof(t_room *))))
	{
		free(g->mem);
		free(g);
		on_error_exit();
	}
	if (!(g->mem->temp = (t_room **)malloc(sizeof(t_room *))))
	{
		free(g->mem->full_stack);
		free(g->mem);
		free(g);
		on_error_exit();
	}
	*(g->mem->full_stack) = NULL;
	*(g->mem->temp) = NULL;
	link_to_stack(g->mem, in_room((void *)g), 1);
	link_to_stack(g->mem, in_room((void *)(g->mem)), 1);
	link_to_stack(g->mem, in_room((void *)(g->mem->full_stack)), 1);
	link_to_stack(g->mem, in_room((void *)(g->mem->temp)), 1);
	g->env = NULL;
}

t_g		*init_env(void)
{
	t_g		*global;

	if (!(global = (t_g*)malloc(sizeof(t_g))))
		on_error_exit();
	if (!(global->mem = (t_mem*)malloc(sizeof(t_mem))))
	{
		free(global);
		on_error_exit();
	}
	init_mem(global);
	return (global);
}

void	*ft_alloc(t_mem *mem, size_t t)
{
	void	*alloc;

	if (!(alloc = (void*)malloc(t)))
		ft_error(mem);
	else
		link_to_stack(mem, in_room(alloc), 1);
	return (alloc);
}

void	*ft_alloc_t(t_mem *mem, size_t t)
{
	void	*alloc;

	if (!(alloc = (void *)malloc(t)))
		ft_error(mem);
	else
		link_to_stack(mem, in_room(alloc), 2);
	return (alloc);
}
