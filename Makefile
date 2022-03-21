# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spzona <spzona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 15:05:01 by spzona            #+#    #+#              #
#    Updated: 2022/03/21 20:10:24 by spzona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2

MLX = mlx/libmlx.a
MLX_PATH = mlx/

LIBFT = libft/libft.a
LIBFT_PATH = libft/

SRC =	ft_so_long.c              ft_print_msg.c           ft_check_file_validity.c   \
		ft_get_next_line.c        ft_initialize.c          ft_parse_map.c             \
		ft_check_map_validity.c   ft_display_program.c     ft_put_texture.c           \
		ft_draw.c                 ft_handle_moves.c        ft_free_memory.c           \

SRC_PATH = src/

OBJ = $(patsubst %.c,%.o,$(addprefix $(SRC_PATH), $(SRC)))
D_FILES = $(patsubst %.c,%.d,$(addprefix $(SRC_PATH), $(SRC)))

all: $(NAME) $(LIBFT) $(MLX) 

%.o: %.c
	@cc $(OPTFLAGS) $(CFLAGS) -c $< -o $@ -MD
	
include $(wildcard $(D_FILES))

$(NAME): $(OBJ)
	@cc $(OPTFLAGS) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Ready to play!"

$(LIBFT): 
	@make -s -C $(LIBFT_PATH)
	@echo "Libft is compiled"

$(MLX):
	@make -s -C $(MLX_PATH)
	@echo "Libmlx is compiled"

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJ) $(D_FILES)
	@echo "OBJ and DEPS are dead"

fclean: clean 
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "Game is dead"

re: fclean all

.PHONY: all clean fclean re