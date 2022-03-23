/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:03:27 by spzona            #+#    #+#             */
/*   Updated: 2022/03/23 17:29:42 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	create_map(t_program *sl)
{
	int	row;

	row = 0;
	sl->game.map = (char **)malloc(sizeof(char *) * sl->game.height);
	if (sl->game.map == NULL)
	{
		ft_show_error("Malloc error\n");
		return (-1);
	}
	while (row < sl->game.height)
	{
		sl->game.map[row] = malloc(sl->game.width + 1);
		if (sl->game.map[row] == NULL)
		{
			ft_show_error("Malloc error\n");
			ft_free_map(sl, row - 1);
			return (-1);
		}
		row++;
	}
	return (1);
}

static int	fill_map(t_program *sl, char *file)
{
	char	*line;
	int		row;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_show_error("Problem with opening the file\n");
		return (-1);
	}
	row = 0;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		ft_strlcpy(&(sl->game.map[row++][0]), line, sl->game.width + 1);
		free(line);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
	{
		ft_show_error("Problem with closing the file\n");
		ft_free_map(sl, sl->game.height - 1);
		return (-1);
	}
	return (0);
}

static int	create_enemies(t_program *sl)
{
	int	i;

	sl->game.enemies_pos = (t_enemy **)malloc(sl->game.enemies
			* sizeof(t_enemy *));
	if (sl->game.enemies_pos == NULL)
	{
		ft_show_error("Malloc erorr\n");
		return (-1);
	}
	i = 0;
	while (i < sl->game.enemies)
	{
		sl->game.enemies_pos[i] = (t_enemy *)malloc(sizeof(t_enemy));
		if (sl->game.enemies_pos[i] == NULL)
		{
			ft_show_error("Malloc error\n");
			ft_free_enemies_pos(sl, i - 1);
			return (-1);
		}
		i++;
	}
	return (1);
}

static void	fill_enemies(t_program *sl)
{
	int	row;
	int	col;
	int	cnt;

	row = 0;
	cnt = 0;
	while (row < sl->game.height)
	{
		col = 0;
		while (col < sl->game.width)
		{
			if (sl->game.map[row][col] == ENEMY)
			{
				sl->game.enemies_pos[cnt]->x = row;
				sl->game.enemies_pos[cnt]->y = col;
				sl->game.enemies_pos[cnt]->direction = 1;
				cnt++;
			}
			col++;
		}
		row++;
	}
}

int	ft_parse_map(t_program *sl, char *file)
{
	int	status;

	if (ft_check_file_validity(sl, file) == -1)
		return (-1);
	status = create_map(sl);
	if (status == -1)
		return (-1);
	status = fill_map(sl, file);
	if (status == -1)
		return (-1);
	if (ft_check_map_validity(sl) == -1)
	{
		ft_free_map(sl, sl->game.height - 1);
		return (-1);
	}
	status = create_enemies(sl);
	if (status == -1)
	{
		ft_free_map(sl, sl->game.height - 1);
		return (-1);
	}
	fill_enemies(sl);
	return (0);
}
