/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:32:38 by spzona            #+#    #+#             */
/*   Updated: 2022/03/21 20:37:18 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG
# define FT_SO_LONG

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>

# define UP 13
# define DOWN 1 
# define LEFT 0
# define RIGHT 2
# define ESC 53

# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define WALL '1'
# define SPACE '0'
# define ENEMY 'B'
# define WINDOW_ZOOM 64

# define BUFFER_SIZE 1024

typedef struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct s_window
{
	void	*addr;
	t_size	size;
}	t_window;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
}	t_enemy;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		line_length;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_game
{
	char	**map;
	t_enemy	**enemies_pos;
	int		width;
	int		height;
	int		players;
	int		player_x;
	int		player_y;
	int		exits;
	int		exit_x;
	int		exit_y;
	int		enemies;
	int		collectibles;
	int		moves;
}	t_game;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_game		game;
	t_image		field;
	t_image		player;
	t_image		wall;
	t_image		collectible;
	t_image		exit;
	t_image		empty;
	t_image		enemy;
}	t_program;

void	ft_show_error(char *error);
void	ft_print_score(t_program *sl);
char	*ft_get_next_line(int fd);
int		ft_initialize_game(t_program *sl);
int		ft_initialize_textures(t_program *sl);
int		ft_parse_map(t_program *sl, char *file);
int		ft_check_file_validity(t_program *sl, char *file);
int		ft_check_map_validity(t_program *sl);
void	ft_display_program(t_program *sl);
int		ft_close_program(t_program *sl);
void	ft_put_texture(t_program *sl, t_image image, int row, int col);
void	ft_draw(t_program *sl);
void	ft_display_score(t_program *sl);
void	ft_lost_game(t_program *sl);
void	ft_collect_collectibles(t_program *sl, int x, int y);
void	ft_check_exit(t_program *sl, int x, int y);
int		ft_check_enemy(t_program *sl, int x, int y);
int		ft_handle_moves(int keycode, t_program *sl);
void	ft_move_enemy(t_program *sl);
void	ft_free_enemies_pos(t_program *sl, int i);
void	ft_free_map(t_program *sl, int row);
void	ft_free_program(t_program *sl);

#endif 