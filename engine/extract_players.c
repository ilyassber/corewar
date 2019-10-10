/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:29:48 by iberchid          #+#    #+#             */
/*   Updated: 2019/10/05 22:27:41 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

char	*get_code(t_core *core, char *path)
{
	int		fd;
	char	*code

	fd = open(path, O_RDONLY);
	code = get_text(core->g, fd, 3216);
	close(fd);
	return (code);
}

void	extract_players(t_core *core, char **args, int n)
{
	int			i;
	t_player	*player;

	i = 0;
	core->p_nbr = n;
	while (i < n)
	{
		player = init_player(core->g, get_code(core, arg[i]), i + 1);
		append_to_hold(core->players, holding(core->g, (void *)player));
		i++;
	}
}
