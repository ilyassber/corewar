/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:36:24 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/12 21:12:54 by iberchid         ###   ########.fr       */
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

void	print_hex(char *str, int line_size, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i % line_size == 0)
		{
			ft_putstr("0x");
			put_char_hex((char)(i / 256));
			put_char_hex((char)(i % 256));
			ft_putstr(" : ");
		}
		put_char_hex(str[i++]);
		ft_putchar(' ');
		if (i % line_size == 0)
			ft_putchar('\n');
	}
}
