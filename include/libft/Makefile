# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 15:03:53 by Jyniemit          #+#    #+#              #
#    Updated: 2025/05/21 10:57:46 by jyniemit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_printf.c		\
		ft_err_exit.c   \
		handle_c.c		\
		handle_s.c		\
		handle_u.c		\
		handle_d.c		\
		handle_p.c		\
		handle_hex_low.c\
		handle_hex_up.c

FLAGS = -Wall -Wextra -Werror
OBJSDIR = ./build/
OBJS = $(addprefix $(OBJSDIR), $(SRCS:.c=.o))
HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

$(OBJSDIR)%.o: %.c | $(OBJSDIR)
	cc $(FLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p build

clean:
	rm -fr	$(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: FLAGS += -g
debug: fclean all

.PHONY: all clean fclean re debug
