/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:53:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/13 12:41:55 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	init_engine(t_core *core)
{
	parse_args(core, core->argv, core->argc);
	extract_players(core);
}

int	engine(t_core *core)
{

}
