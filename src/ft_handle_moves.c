/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:47:19 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 20:05:18 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static void	move_player(t_program *sl, int x, int y)
{
	if (sl->game.map[x][y] == WALL)
		return ;
	sl->game.player_x = x;
	sl->game.player_y = y;
	ft_collect_collectibles(sl, x, y);
	if (ft_check_enemy(sl, x, y) == 1)
		ft_lost_game(sl);
	ft_move_enemy(sl);
	ft_check_exit(sl, x, y);
}

static void	determine_move(int keycode, t_program *sl, int x, int y)
{
	if (keycode == UP)
		move_player(sl, x - 1, y);
	if (keycode == RIGHT)
		move_player(sl, x, y + 1);
	if (keycode == DOWN)
		move_player(sl, x + 1, y);
	if (keycode == LEFT)
		move_player(sl, x, y - 1);
	if (keycode == ESC)
		ft_close_program(sl);
}

int	ft_handle_moves(int keycode, t_program *sl)
{
	int	x;
	int	y;

	x = sl->game.player_x;
	y = sl->game.player_y;
	determine_move(keycode, sl, x, y);
	if (!(sl->game.map[x][y] == EXIT)
		&& !(x == sl->game.player_x && y == sl->game.player_y))
		sl->game.map[x][y] = SPACE;
	ft_draw(sl);
	mlx_put_image_to_window(sl->mlx, sl->window.addr, sl->field.img, 0, 0);
	if (!(x == sl->game.player_x && y == sl->game.player_y))
	{
		sl->game.moves++;
		ft_print_score(sl);
	}
	ft_display_score(sl);
	return (0);
}
