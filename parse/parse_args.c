/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:35:52 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/11 09:43:06 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int		get_dump(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-dump"))
		{
			if ((i + 1) < argc && ft_isnum(argv[i + 1]))
			{
				if (ft_atoi(argv[i + 1]) >= 0)
					return (ft_atoi(argv[i + 1]));
			}
			return (UNEXPECTED_ARG);
		}
		i++;
	}
	return (-1);
}

void	parse_args(t_core *core, char **argv, int argc)
{

}
