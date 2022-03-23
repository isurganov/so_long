/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_validity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:35:57 by spzona            #+#    #+#             */
/*   Updated: 2022/03/23 17:29:42 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	forbidden_symbols(t_program *sl, int row, int col, char c)
{
	if (!(c == COLLECTIBLE || c == PLAYER || c == EXIT || c == WALL
			|| c == SPACE || c == ENEMY))
	{
		ft_show_error("Wrong char on the map\n");
		return (-1);
	}
	if (row == 0 || row == sl->game.height - 1 || col == 0
		|| col == sl->game.width - 1)
	{
		if (sl->game.map[row][col] != WALL)
		{
			ft_show_error("Map should be surrounded by walls\n");
			return (-1);
		}
	}
	return (1);
}

static void	process_symbols(t_program *sl, int row, int col)
{
	if (sl->game.map[row][col] == COLLECTIBLE)
		sl->game.collectibles++;
	else if (sl->game.map[row][col] == PLAYER)
	{
		sl->game.players++;
		sl->game.player_x = row;
		sl->game.player_y = col;
	}
	else if (sl->game.map[row][col] == EXIT)
	{
		sl->game.exits++;
		sl->game.exit_x = row;
		sl->game.exit_y = col;
	}
	else if (sl->game.map[row][col] == ENEMY)
		sl->game.enemies++;
}

static int	check_symbols(t_program *sl)
{
	int	row;
	int	col;

	row = 0;
	while (row < sl->game.height)
	{
		col = 0;
		while (col < sl->game.width)
		{
			if (forbidden_symbols(sl, row, col, sl->game.map[row][col]) == -1)
				return (-1);
			process_symbols(sl, row, col);
			col++;
		}
		row++;
	}
	return (1);
}

int	ft_check_map_validity(t_program *sl)
{
	if (check_symbols(sl) == -1)
		return (-1);
	if (sl->game.players != 1)
	{
		ft_show_error("Should be at least/only one player\n");
		return (-1);
	}
	if (sl->game.exits != 1)
	{
		ft_show_error("Should be at least/only one exit\n");
		return (-1);
	}
	if (sl->game.collectibles == 0)
	{
		ft_show_error("Should be at least/only one collectible\n");
		return (-1);
	}
	return (1);
}
