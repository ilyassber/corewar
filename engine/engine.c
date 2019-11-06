/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:53:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/06 22:48:09 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void static	init_engine(t_core *core)
{
	parse_args(core, core->argv, core->argc);
	extract_players(core);
	init_procs(core);
	init_area(core);
}

int			engine(t_core *core)
{
	init_engine(core);
	while (procs_len(core))
	{
		if (core->cycle == core->arg->dump)
			dump(core);
		check_procs(core);
		RUN
		(core->cycle)++;
		if (core->cycle == (core->last_check + core->ctd))
			max_check(core);
		print_procs(core);
	}
	return (SUCCESS);
}
