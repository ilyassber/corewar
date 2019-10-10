/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:11:14 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/22 17:14:14 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	read_value(char *mem, int n)
{
	unsigned int	value;
	unsigned int	up;
	unsigned char	c;
	int				i;

	value = 0;
	up = 256;
	i = 0;
	while (i < n)
	{
		c = *((unsigned char *)(mem + i));
		if (i > 0)
			value = value * up + c;
		else
			value = c;
		i++;
	}
	if (n == 1)
		return ((int)((signed char)value));
	else if (n == 2)
		return ((int)((signed short)value));
	return ((signed int)value);
}
