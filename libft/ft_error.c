/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <iberchid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:51:05 by iberchid          #+#    #+#             */
/*   Updated: 2019/07/23 20:50:34 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	on_error_exit(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

void	ft_error(t_mem *mem)
{
	free_stack(mem);
	on_error_exit();
}
