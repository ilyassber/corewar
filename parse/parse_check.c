/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:31:16 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/11 09:47:57 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	check_order(t_args *args, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n"))
		{
			args->order = 1;
			return (SUCCESS);
		}
		i++;
	}
	return (ERROR);
}

int	check_flags(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (!(ft_strcmp(argv[i], "-n") || ft_strcmp(argv[i], "-dump") ||
						ft_strcmp(argv[i], "-v")))
				return (UNEXPECTED_FLAG);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_players(t_args *args, char **argv, int argc)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") && (i + 1) < argc)
		{
			args->n += (n - ft_atoi(argv[i + 1]));
			i++;
			n++;
		}
		else if (ft_strcmp(argv[i], "-n"))
			return (UNEXPECTED_ARG);
		i++;
	}
	if (args->n == 0)
		return (SUCCESS);
	else
		return (BAD_ORDER);
}

int	is_op(char *mem)
{
	if (*mem > 0 && *mem < 17)
		return ((int)*mem);
	return (ERROR);
}
