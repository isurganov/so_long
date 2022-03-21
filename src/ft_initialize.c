/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:21:21 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 16:40:39 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	convert_textures(t_program *sl, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(sl->mlx, path, &(image->width),
			&(image->height));
	if (image->img == 0)
	{
		ft_show_error("Something wrong with textures\n");
		return (-1);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	return (1);
}

int	ft_initialize_textures(t_program *sl)
{
	int	status;

	status = convert_textures(sl, &(sl->player), "./textures/player.xpm");
	if (status == -1)
		return (-1);
	status = convert_textures(sl, &(sl->wall), "./textures/wall.xpm");
	if (status == -1)
		return (-1);
	status = convert_textures(sl, &(sl->empty), "./textures/empty.xpm");
	if (status == -1)
		return (-1);
	status = convert_textures(sl, &(sl->collectible),
			"./textures/collectible.xpm");
	if (status == -1)
		return (-1);
	status = convert_textures(sl, &(sl->exit), "./textures/exit.xpm");
	if (status == -1)
		return (-1);
	status = convert_textures(sl, &(sl->enemy), "./textures/enemy.xpm");
	if (status == -1)
		return (-1);
	return (1);
}

int	ft_initialize_game(t_program *sl)
{
	sl->game.players = 0;
	sl->game.player_x = 0;
	sl->game.player_y = 0;
	sl->game.exits = 0;
	sl->game.exit_x = 0;
	sl->game.exit_y = 0;
	sl->game.enemies = 0;
	sl->game.collectibles = 0;
	sl->game.width = 0;
	sl->game.height = 0;
	sl->game.moves = 0;
	return (1);
}
