/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:44:19 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/21 13:05:07 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	op_aff(t_core *core, t_proc *proc)
{
	int		value;
	char	c;

	value = get_arg_value(core, proc, 0, 0) % 256;
	if (value <= 0)
		return (0);
	c = (char)value;
	//write(1, &c, 1);
	return (1);
}
