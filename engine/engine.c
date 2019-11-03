/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:53:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/24 08:59:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void static	init_engine(t_core *core)
{
	parse_args(core, core->argv, core->argc);
	EST
	extract_players(core);
	init_procs(core);
}

int			engine(t_core *core)
{
	init_engine(core);
	while (procs_len(core))
	{
		RUN
		check_procs(core);
		(core->cycle)++;
		if (core->cycle == (core->last_check + core->ctd))
			max_check(core);
	}
	return (SUCCESS);
}
