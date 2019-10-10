/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:38:55 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/28 11:13:22 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	is_reg(t_proc *proc, int arg)
{
	if (proc->inst->args_type[arg] != 1)
		return (1);
	if (proc->inst->args[arg] < 1 || proc->inst->args[arg] > 16)
		return (0);
	return (1);
}
