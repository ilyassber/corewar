/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:35:52 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/12 19:46:12 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

int		jump_flags(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n"))
			i = i + 2;
		else if (ft_strcmp(argv[i], "-dump"))
			i = i + 2;
		else if (ft_strcmp(argv[i], "-v"))
			i++;
		else
			return (i);
	}
	return (UNVALID_ARG);
}

char	*get_arg_by_order(char **argv, int argc, int n)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") && n == ft_atoi(argv[i + 1]))
			return (argv[i + 2]);
		i++;
	}
	return (NULL);
}

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

void	parse_args_check(t_core *core, char **argv, int argc)
{
	on_error(core->g, check_flags(argv, argc));
	on_error(core->g, check_players(argv, argc));
	if (check_order(core->args, argv, argc))
		core->args->order = jump_flags(argv, argc);
}

void	parse_args(t_core *core, char **argv, int argc)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	parse_args_check(core, argv, argc);
	if (core->args->n > 4)
		on_error(core->g, UNEXPECTED_ARG);
	while (i < core->args->n)
	{
		if (core->args->order)
			append_to_hold(core->args->paths, holding(core->g,
						(void *)(argv[core->args->order + i])));
		else
		{
			path = get_arg_by_order(argv, argc, (i + 1));
			if (!path)
				on_error(core->g, UNVALID_ARG);
			append_to_hold(core->args->paths, holding(core->g, (void *)path));
			
		}
		i++;
	}
}
