/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:36:24 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/17 13:21:23 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	int_to_hex(int n)
{
	if (n <= 9)
		return (48 + n);
	else
		return (87 + n);
}

void	put_char_hex(char c)
{
	ft_putchar(int_to_hex((unsigned char)c / 16));
	ft_putchar(int_to_hex((unsigned char)c % 16));
}

void	print_hex(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_char_hex(str[i++]);
		if(i % 2 == 0)
			ft_putchar(' ');
		if (i % 16 == 0)
			ft_putchar('\n');
	}
}
