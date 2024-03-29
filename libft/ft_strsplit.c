/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:01:31 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/22 15:48:29 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_words(const char *str, char c)
{
	int	i;
	int	j;
	int access;

	i = 0;
	j = 0;
	access = 1;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (access == 1))
		{
			j++;
			access = 0;
		}
		else if (str[i] == c)
			access = 1;
		i++;
	}
	return (j);
}

static int	nbr_letters(const char *str, char c)
{
	int	i;

	i = 0;
	while ((str[i] != '\0') && (str[i] != c))
	{
		i++;
	}
	return (i);
}

static int	fill_words(char *str1, char const *str2, char c, int n)
{
	int	i;

	i = 0;
	while ((str2[n] != c) && (str2[n] != '\0'))
		str1[i++] = str2[n++];
	str1[i] = '\0';
	while (str2[n] == c)
		n++;
	return (n);
}

char		**ft_strsplit(t_g *grh, char const *s, char c)
{
	int		i;
	int		t;
	char	**tab;

	if (s)
	{
		tab = (char**)ft_alloc(grh->mem, sizeof(char*) * (nbr_words(s, c) + 1));
		i = 0;
		t = 0;
		while (s[i] == c)
			i++;
		while (s[i] != '\0')
		{
			tab[t] = (char*)ft_alloc(grh->mem,
					sizeof(char) * (nbr_letters(s + i, c) + 1));
			i = fill_words(tab[t], s, c, i);
			t++;
		}
		tab[t] = 0;
		return (tab);
	}
	else
		return (NULL);
}
