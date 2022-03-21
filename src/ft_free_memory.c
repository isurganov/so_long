/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:41:09 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 18:54:04 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

void	ft_free_enemies_pos(t_program *sl, int i)
{
	while (i >= 0)
		free(sl->game.enemies_pos[i--]);
	free(sl->game.enemies_pos);
}

void	ft_free_map(t_program *sl, int row)
{
	while (row >= 0)
		free(sl->game.map[row--]);
	free(sl->game.map);
}

void	ft_free_program(t_program *sl)
{
	free(sl);
}
