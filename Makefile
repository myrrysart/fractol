# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 01:12:07 by jyniemit          #+#    #+#              #
#    Updated: 2025/05/30 11:02:01 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDEDIR = ./include/
LIBFTDIR = $(INCLUDEDIR)/libft/
MLXDIR = $(INCLUDEDIR)/minilibx-linux/
LIBFT = $(LIBFTDIR)libft.a
MLX = $(MLXDIR)libmlx_Linux.a
HEADERS = $(INCLUDEDIR)fractal.h

SRC = ./src/main.c \
	./src/palette.c \
	./src/palette_continued.c \
	./src/optimization.c \
	./src/palette_utils.c \
	./src/double_parsing.c \
	./src/double_parsing_utils.c \
	./src/handle_input.c \
	./src/animation.c \
	./src/rendering_utils.c \
	./src/julia_rendering.c \
	./src/burning_ship_rendering.c \
	./src/mandelbrot_rendering.c \
	./src/rendering.c
OBJDIR = ./build/
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))


all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lft -o $(NAME)


$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX):
	@make -C $(MLXDIR)

$(OBJDIR)%.o: ./src/%.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -I$(MLXDIR) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

debug: fclean
	@make -C $(LIBFTDIR) debug
	@make -C $(MLXDIR)
	$(MAKE) CFLAGS="$(CFLAGS) -g" all

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --suppressions=../mlx_suppressions.supp --show-leak-kinds=all ./$(NAME)
.PHONY: all clean fclean re debug valgrind
