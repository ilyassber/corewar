/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:50:51 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/07 19:05:30 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	main(int argc, char **argv)
{
	t_g			*g;
	t_core		*core;
	t_player	*player;
	char		*code;
	int			fd;

	if (argc == 2)
	{
		g = init_env();
		core = (t_core *)ft_alloc(g->mem, sizeof(t_core));
		core->g = g;
		fd = open(argv[1], O_RDONLY);
		code = get_text(g, fd, 3216);
		player = init_player(g, code, 0);
		ft_putendl(player->name);
		ft_putendl(player->comment);
		ft_putnbr(player->size);
		ft_putchar('\n');
		print_hex(player->exe, 1024);
		ft_putchar('\n');
		core->area = player->exe;
		parser_loop(core);
	}
	return (0);
}
