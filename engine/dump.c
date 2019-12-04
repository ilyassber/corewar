/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:40:20 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 12:20:36 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	dump(t_core *core)
{
	t_g	*g;

	g = core->g;
	print_hex(core->area, 64, MEM_SIZE);
	free_stack(core->g->mem);
	exit(0);
}
