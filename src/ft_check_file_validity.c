/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:59:42 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 20:29:46 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_so_long.h"

static int	check_file_name(char *file)
{
	int	size;

	size = (int)ft_strlen(file);
	if (size < 5)
	{
		ft_show_error("Wrong file name\n");
		return (-1);
	}
	if (ft_strncmp(&file[size - 4], ".ber", 4) != 0)
	{
		ft_show_error("Wrong file extension\n");
		return (-1);
	}
	return (1);
}

static int	close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_show_error("Problem with closing the file\n");
		return (-1);
	}
	else
		return (1);
}

static int	read_file(t_program *sl, int fd, char *line)
{
	while (line != NULL)
	{
		if (sl->game.width != (int) ft_strlen(line))
		{
			ft_show_error("Map does not have a correct shape\n");
			close(fd);
			return (-1);
		}
		sl->game.height++;
		free(line);
		line = ft_get_next_line(fd);
	}
	return (1);
}

static int	check_map_size(t_program *sl, char *file)
{
	char	*line;
	int		status;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_show_error("Problem with opening the file\n");
		return (-1);
	}
	line = ft_get_next_line(fd);
	if (line == NULL)
	{
		ft_show_error("Empty map!\n");
		close(fd);
		return (-1);
	}
	sl->game.width = (int)ft_strlen(line);
	status = read_file(sl, fd, line);
	if (status == -1)
		return (-1);
	return (close_file(fd));
}

int	ft_check_file_validity(t_program *sl, char *file)
{
	if (check_file_name(file) == -1)
		return (-1);
	if (check_map_size(sl, file) == -1)
		return (-1);
	return (1);
}
