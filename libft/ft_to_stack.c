/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:48:40 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/23 23:55:12 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_to_stack(t_g *g, char *str)
{
	int		i;
	int		j;
	char	*line;

	if (str)
	{
		i = ft_strlen(str);
		j = 0;
		line = (char *)ft_alloc(g->mem, (sizeof(char) * (i + 1)));
		while (j < i)
		{
			line[j] = str[j];
			j++;
		}
		line[j] = '\0';
		return (line);
	}
	return (NULL);
}
