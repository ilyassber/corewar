/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:28:05 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/12 13:50:34 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

static void	print_error(int code)
{
	if (code == 0)
		ft_putstr_fd("ERROR\n", 2);
	else if (code == -10)
		ft_putstr_fd("ERROR : UNEXPECTED ARGUMENT\n", 2);
	else if (code == -11)
		ft_putstr_fd("ERROR : UNEXPECTED FLAG\n", 2);
	else if (code == -12)
		ft_putstr_fd("ERROR : BAD ARGUMENTS ORDER\n", 2);
	else if (code == -13)
		ft_putstr_fd("ERROR : UNVALID ARGUMENT\n", 2);
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
