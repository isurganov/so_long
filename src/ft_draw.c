/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:18 by spzona            #+#    #+#             */
/*   Updated: 2022/03/23 17:29:42 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_cell(t_program *sl, int row, int col)
{
	if (sl->game.map[row][col] == WALL)
		ft_put_texture(sl, sl->wall, row * WINDOW_ZOOM, col * WINDOW_ZOOM);
	else
		ft_put_texture(sl, sl->empty, row * WINDOW_ZOOM, col * WINDOW_ZOOM);
	if (sl->game.map[row][col] == COLLECTIBLE)
		ft_put_texture(sl, sl->collectible, row * WINDOW_ZOOM,
			col * WINDOW_ZOOM);
	if (sl->game.map[row][col] == EXIT)
		ft_put_texture(sl, sl->exit, row * WINDOW_ZOOM, col * WINDOW_ZOOM);
	if (row == sl->game.player_x && col == sl->game.player_y)
		ft_put_texture(sl, sl->player, row * WINDOW_ZOOM, col * WINDOW_ZOOM);
	if (ft_check_enemy(sl, row, col) == 1)
		ft_put_texture(sl, sl->enemy, row * WINDOW_ZOOM, col * WINDOW_ZOOM);
}

void	ft_draw(t_program *sl)
{
	int	row;
	int	col;

	row = 0;
	while (row < sl->game.height)
	{
		col = 0;
		while (col < sl->game.width)
		{
			draw_cell(sl, row, col);
			col++;
		}
		row++;
	}
}

void	ft_display_score(t_program *sl)
{
	char	*num;
	char	*line;

	num = ft_itoa(sl->game.moves);
	line = ft_strjoin("SCORE: ", num);
	mlx_string_put(sl->mlx, sl->window.addr, 20, 40, 0xffffff, line);
	free(num);
	free(line);
}
