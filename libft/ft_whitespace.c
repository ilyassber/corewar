/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:37:35 by iberchid          #+#    #+#             */
/*   Updated: 2019/05/31 00:40:55 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
			c == '\r' || c == ' ')
		return (1);
	return (0);
}
