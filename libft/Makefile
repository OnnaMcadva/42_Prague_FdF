# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annavm <annavm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 21:18:47 by anmakaro          #+#    #+#              #
#    Updated: 2024/12/22 22:12:17 by annavm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isdigit.c ft_itoa.c \
		ft_memset.c ft_putendl_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlen.c ft_strncmp.c ft_strtrim.c get_next_line.c \
		get_next_line_utils.c ft_strcmp.c \
		ft_memcpy.c ft_memmove.c ft_strtol.c ft_round.c \
		ft_common.c ft_decimal_integer.c ft_hexadecimal.c \
		ft_init_format.c ft_percent_sign.c ft_pointer.c ft_printf.c \
		ft_single_character.c ft_string.c ft_unsigned_decimal.c		

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

