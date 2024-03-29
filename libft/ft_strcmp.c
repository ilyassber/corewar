/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:45:32 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/18 10:51:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (((int)str1[i] == (int)str2[i]) && str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (((int)str1[i] - (int)str2[i]) == 0)
		return (1);
	return (0);
}
