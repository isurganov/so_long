/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:03:09 by spzona            #+#    #+#             */
/*   Updated: 2022/03/23 17:29:42 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lost_game(t_program *sl)
{
	ft_putstr_fd("Enemy caught your ass! See you again!\n", 1);
	ft_free_enemies_pos(sl, sl->game.enemies - 1);
	ft_free_map(sl, sl->game.height - 1);
	ft_free_program(sl);
	exit(0);
}

void	ft_collect_collectibles(t_program *sl, int x, int y)
{
	if (sl->game.map[x][y] == COLLECTIBLE)
	{
		sl->game.collectibles--;
		sl->game.map[x][y] = SPACE;
	}
}

void	ft_check_exit(t_program *sl, int x, int y)
{
	if (sl->game.map[x][y] == EXIT)
	{
		if (sl->game.collectibles == 0)
		{
			sl->game.moves++;
			ft_putstr_fd("Congratulations! You won! ", 1);
			ft_print_score(sl);
			ft_putstr_fd("See ya again!\n", 1);
			ft_free_enemies_pos(sl, sl->game.enemies - 1);
			ft_free_map(sl, sl->game.height - 1);
			ft_free_program(sl);
			exit(0);
		}
	}
}

int	ft_check_enemy(t_program *sl, int x, int y)
{
	int	i;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < sl->game.enemies)
	{
		enemy_x = (*sl->game.enemies_pos[i]).x;
		enemy_y = (*sl->game.enemies_pos[i]).y;
		if (x == enemy_x && y == enemy_y)
			return (1);
		i++;
	}
	return (-1);
}
