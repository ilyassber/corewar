/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:08:51 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/25 13:45:15 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

void	cycle_info(t_core *core)
{
	ft_putstr("##cycle\n");
	ft_putnbr(core->cycle);
	ft_putstr("\n##ctd\n");
	ft_putnbr(core->ctd);
	ft_putstr("\n##next_ctd\n");
	ft_putnbr(core->last_check + core->ctd - core->cycle);
	ft_putstr("\n##max_check\n");
	ft_putnbr(core->max_check);
	ft_putchar('\n');
}
