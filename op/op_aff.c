/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:44:19 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/30 22:02:55 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_aff(t_core *core, t_proc *proc)
{
	int	value;

	if (!is_reg(proc, 0))
		return (0);
	value = get_arg_value(core, proc, 0, 0);
	ft_putchar((char)(value % 256));
	return (1);
}
