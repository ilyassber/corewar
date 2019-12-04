/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:28:05 by iberchid          #+#    #+#             */
/*   Updated: 2019/12/04 22:03:19 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

static void	print_error(int code)
{
	if (code == ERROR)
		ft_putstr_fd("ERROR\n", 2);
	else if (code == UNEXPECTED_ARG)
		ft_putstr_fd("ERROR : UNEXPECTED ARGUMENT\n", 2);
	else if (code == UNEXPECTED_FLAG)
		ft_putstr_fd("ERROR : UNEXPECTED FLAG\n", 2);
	else if (code == BAD_ORDER)
		ft_putstr_fd("ERROR : BAD ARGUMENTS ORDER\n", 2);
	else if (code == UNVALID_ARG)
		ft_putstr_fd("ERROR : UNVALID ARGUMENT\n", 2);
	else if (code == UNVALID_PATH)
		ft_putstr_fd("ERROR : UNVALID PATH\n", 2);
	else if (code == OVER_MAX_SIZE)
		ft_putstr_fd("ERROR : PLAYER SIZE OVER MAX SIZE\n", 2);
}

void		on_error(t_g *g, int code)
{
	if (code <= 0)
	{
		print_error(code);
		free_stack(g->mem);
		exit(1);
	}
}
