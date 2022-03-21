/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:10:46 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 16:40:15 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	make_enemy_move(t_program *sl, int i, int x, int y)
{
	if (sl->game.player_x == x && sl->game.player_y == y)
	{
		(*sl->game.enemies_pos[i]).x = x;
		ft_lost_game(sl);
	}
	else if (sl->game.map[x][y] == WALL || ft_check_enemy(sl, x, y) == 1)
		(*sl->game.enemies_pos[i]).direction *= -1;
	else
		(*sl->game.enemies_pos[i]).x = x;
}

void	ft_move_enemy(t_program *sl)
{
	int	i;
	int	x;
	int	y;
	int	d;

	i = 0;
	while (i < sl->game.enemies)
	{
		x = (*sl->game.enemies_pos[i]).x;
		y = (*sl->game.enemies_pos[i]).y;
		d = (*sl->game.enemies_pos[i]).direction;
		if (d == 1)
			make_enemy_move(sl, i, x - 1, y);
		else
			make_enemy_move(sl, i, x + 1, y);
		i++;
	}
}
