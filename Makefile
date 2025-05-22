# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 01:12:07 by jyniemit          #+#    #+#              #
#    Updated: 2025/05/23 01:41:52 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal
CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDEDIR = ./include/
LIBFTDIR = $(INCLUDEDIR)/libft/
MLXDIR = $(INCLUDEDIR)/minilibx-linux/
LIBFT = $(LIBFTDIR)libft.a
MLX = $(MLXDIR)libmlx_Linux.a
HEADERS = $(INCLUDEDIR)fractal.h

SRC = ./src/main.c

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
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@make -C $(LIBFTDIR) fclean

debug: fclean
	@make -C $(LIBFTDIR) debug
	$(MAKE) CFLAGS="$(CFLAGS) -g" all

re: fclean all

.PHONY: all clean fclean re debug
