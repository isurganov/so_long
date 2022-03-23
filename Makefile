# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spzona <spzona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 14:26:27 by spzona            #+#    #+#              #
#    Updated: 2022/03/22 15:51:30 by spzona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OPTFLAGS = -O2
CFLAGS = -Wall -Wextra -Werror

LIBFT =	libft/libft.a
LIBFT_PATH = libft/

MLX = mlx/libmlx.a
MLX_PATH = mlx/

SRC_PATH = src/
SRC =	ft_so_long.c	ft_print_msg.c	ft_check_file_validity.c   \
		ft_get_next_line.c	ft_initialize.c          ft_parse_map.c             \
		ft_check_map_validity.c   ft_display_program.c     ft_put_texture.c           \
		ft_draw.c                 ft_handle_moves.c        ft_free_memory.c           \
		ft_actions.c              ft_move_enemy.c	
				
OBJ = $(patsubst %.c,%.o,$(addprefix $(SRC_PATH),$(SRC)))
D_FILES = $(patsubst %.c,%.d,$(addprefix $(SRC_PATH), $(SRC)))

all:	$(LIBFT) $(MLX) $(NAME)

$(LIBFT):		
		@echo "Compiling libft..."
		@make -s -C $(LIBFT_PATH)
		@echo "Libft is compliled"

$(MLX):		
		@echo "Compiling libmlx..."
		@make -s -C $(MLX_PATH)
		@echo "Libmlx is compliled"

$(NAME):	$(OBJ)
		@cc $(CFLAGS) $(OPTFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Game is ready to roll!"

%.o: %.c
		@cc $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean: 
		@make -C $(LIBFT_PATH) clean
		@make -C $(MLX_PATH) clean
		@rm -f $(OBJ) $(D_FILES)
		@echo "OBJS and DEPS are dead"

fclean:	clean
		@make -C $(LIBFT_PATH) fclean
		@rm -f $(NAME)
		@echo "Game is dead"

re:	fclean all

.PHONY: all clean fclean re