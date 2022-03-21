# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spzona <spzona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:26:43 by spzona            #+#    #+#              #
#    Updated: 2022/03/20 15:07:53 by spzona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra 

NAME = libft.a

all: $(NAME)

SRC = ft_isdigit.c    ft_memset.c     ft_strchr.c     ft_strlen.c     ft_tolower.c \
		ft_atoi.c       ft_isprint.c     ft_strcpy.c     ft_strmapi.c  ft_toupper.c \
		ft_bzero.c      ft_itoa.c       ft_putchar_fd.c ft_strdup.c     ft_strncmp.c  \
		ft_calloc.c     ft_memchr.c     ft_putendl_fd.c ft_striteri.c   ft_strnstr.c \
		ft_isalnum.c    ft_memcmp.c     ft_putnbr_fd.c  ft_strjoin.c    ft_strrchr.c \
		ft_isalpha.c    ft_memcpy.c     ft_putstr_fd.c  ft_strlcat.c    ft_strtrim.c \
		ft_isascii.c    ft_memmove.c    ft_split.c      ft_strlcpy.c    ft_substr.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "$(NAME) created"
		@ranlib $(NAME)
		@echo "$(NAME) indexed"

%.o: %.c $(HEADER)
		@gcc $(FLAG) -c $< -o $@ -I $(HEADER)

clean:
		@rm -f $(OBJ)
		@echo "OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "OBJ deleted"
	
re: fclean all

.PHONY: all, clean, fclean, re