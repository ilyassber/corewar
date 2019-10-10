/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_until.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:47:45 by iberchid          #+#    #+#             */
/*   Updated: 2019/09/15 23:28:27 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut_until(t_g *g, char *str, int n, int pass)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != '\0' && i < n)
		i++;
	if (pass == 0)
		i = n;
	new = (char *)ft_alloc(g->mem, (sizeof(char) * (i + 1)));
	new[i] = '\0';
	while (i-- > 0)
		new[i] = str[i];
	return (new);
}
