/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:29:48 by iberchid          #+#    #+#             */
/*   Updated: 2019/11/12 21:49:34 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core.h"

char static	*get_code(t_core *core, char *path)
{
	int		fd;
	char	*code;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		on_error(core->g, UNVALID_PATH);
	code = get_text(core->g, fd, 3216);
	close(fd);
	return (code);
}

void		extract_players(t_core *core)
{
	int			i;
	t_player	*player;
	t_hold		*path;

	i = core->arg->n;
	path = *(core->arg->paths);
	while (i >= 0 && path)
	{
		player = init_player(core->g, get_code(core,
					(char *)(path->mem)), i);
		append_to_hold(core->players, holding(core->g, (void *)player));
		path = path->next;
		i--;
	}
}
