/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 23:28:36 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/16 22:36:12 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_text(t_g *g, int fd, int size)
{
	char	*c;
	int		rd;
	int		i;
	char	*text;

	i = 0;
	text = (char *)ft_alloc(g->mem, sizeof(char) * size);
	c = (char *)ft_alloc(g->mem, sizeof(char));
	rd = read(fd, c, 1);
	while (rd == 1 && i < size)
	{
		text[i++] = *c;
		rd = read(fd, c, 1);
	}
	while (i < size)
		text[i++] = '\0';
	return (text);
}
