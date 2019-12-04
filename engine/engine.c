/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:53:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 15:01:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void		init_engine(t_core *core)
{
	parse_args(core, core->argv, core->argc);
	extract_players(core);
	init_procs(core);
	init_area(core);
	intro_players(core);
	normal_out(core);
}

int			engine(t_core *core)
{
	while (procs_len(core) && core->ctd > 0)
	{
		/*
		ft_putstr("ctd : ");
		ft_putnbr(core->ctd);
		ft_putstr(" - procs : ");
		ft_putnbr(procs_len(core));
		ft_putstr("\n");
		*/
		if (core->cycle == core->arg->dump)
			dump(core);
		check_procs(core);
		(core->cycle)++;
		//ft_putstr("/\\/\\/\\/\\/\\/\\/\\\n");
		//ft_putnbr(core->cycle);
		//ft_putstr("\n");
		if (core->cycle == (core->last_check + core->ctd))
			max_check(core);
		/*
		ft_putstr("ctd : ");
		ft_putnbr(core->ctd);
		ft_putstr(" - until ctd : ");
		ft_putnbr(core->cycle - core->last_check);
		ft_putstr("\n");
		*/
		//print_procs(core);
	}
	print_winner(core);
	return (SUCCESS);
}
