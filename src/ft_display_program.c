/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_program.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:17:38 by spzona            #+#    #+#             */
/*   Updated: 2022/03/23 17:29:42 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_program(t_program *sl)
{
	ft_putstr_fd("Game is aborted. See you again!\n", 1);
	ft_free_enemies_pos(sl, sl->game.enemies - 1);
	ft_free_map(sl, sl->game.height - 1);
	ft_free_program(sl);
	exit(0);
}

void	ft_display_program(t_program *sl)
{
	sl->window.size.x = WINDOW_ZOOM * sl->game.width;
	sl->window.size.y = WINDOW_ZOOM * sl->game.height;
	sl->mlx = mlx_init();
	sl->window.addr = mlx_new_window(sl->mlx, sl->window.size.x,
			sl->window.size.y, "sl_by_spzona");
	sl->field.img = mlx_new_image(sl->mlx, sl->window.size.x,
			sl->window.size.y);
	sl->field.addr = mlx_get_data_addr(sl->field.img, &(sl->field.bpp),
			&(sl->field.line_length), &(sl->field.endian));
	ft_initialize_textures(sl);
	ft_draw(sl);
	mlx_put_image_to_window(sl->mlx, sl->window.addr, sl->field.img, 0, 0);
	ft_print_score(sl);
	ft_display_score(sl);
	mlx_hook(sl->window.addr, 2, 1L, ft_handle_moves, sl);
	mlx_hook(sl->window.addr, 17, 1L << 17, ft_close_program, sl);
	mlx_loop(sl->mlx);
}
