/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:35:44 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 20:24:04 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static unsigned int	mlx_get_pixel(t_image *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (y * img->bpp / 8 + x * img->line_length)));
}

static unsigned int	check_default_pixel(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

static void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->bpp / 8 + x * img->line_length);
	*(unsigned int *)dst = color;
}

void	ft_put_texture(t_program *sl, t_image image, int row, int col)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < image.height)
	{
		j = 0;
		while (j < image.width)
		{
			color = mlx_get_pixel(&image, i, j);
			if (color != check_default_pixel(255, 0, 0, 0))
				my_mlx_pixel_put(&(sl->field), row + i, col + j, color);
			j++;
		}
		i++;
	}
}
