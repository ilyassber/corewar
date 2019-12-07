/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:03:35 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 15:12:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	normal_out(t_core *core)
{
	if (core->arg->v)
	{
		print_hex(core->area, 64, MEM_SIZE);
		print_players(core);
	}
}

void	loop_out(t_core *core)
{
	if (core->arg->v)
	{
		cycle_info(core);
		procs_info(core);
		players_info(core);
		ft_putstr("##map\n");
		print_hex(core->area, 64, MEM_SIZE);
	}
}
