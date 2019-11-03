/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:31:16 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/18 10:50:12 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int	check_order(t_arg *arg, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n"))
		{
			arg->order = 0;
			return (0);
		}
		i++;
	}
	return (1);
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

int	check_players(t_arg *arg, char **argv, int argc)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") && (i + 2) < argc)
		{
			n++;
			arg->n += (n - ft_atoi(argv[i + 1]));
			i++;
		}
		else if (ft_strcmp(argv[i], "-n"))
			return (UNEXPECTED_ARG);
		i++;
	}
	if (arg->n != 0)
		return (BAD_ORDER);
	if (n > 0)
		arg->n = n;
	else
		arg->n = argc - jump_flags(argv, argc);
	return (SUCCESS);
}

int	is_op(char *mem)
{
	if (*mem > 0 && *mem < 17)
		return ((int)*mem);
	return (ERROR);
}
