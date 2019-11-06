/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:36:24 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/05 13:12:22 by iberchid         ###   ########.fr       */
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
		put_char_hex(str[i++]);
		if (i % line_size == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}
