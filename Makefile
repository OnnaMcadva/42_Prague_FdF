# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annavm <annavm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:35:57 by annavm            #+#    #+#              #
#    Updated: 2024/06/16 15:26:35 by annavm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR   = \033[0;39m
GRAY        = \033[0;90m
RED         = \033[0;91m
GREEN       = \033[0;92m
YELLOW      = \033[0;93m
BLUE        = \033[0;94m
MAGENTA     = \033[0;95m
CYAN        = \033[0;96m
WHITE       = \033[0;97m
ORANGE      = \033[38;5;222m
GREEN_BR    = \033[38;5;118m
YELLOW_BR   = \033[38;5;227m
PINK_BR     = \033[38;5;206m
BLUE_BR     = \033[38;5;051m
PINK_BRR     = \033[38;5;219m

# Text styles
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLINK       = \033[5m

# Project
NAME        = fdf
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
AR          = ar
ARFLAGS     = rcs
RM          = rm -rf

# Directories
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = incs
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# Files
SRC_FILES   = fdf_common.c fdf.c map_color.c map_get.c map_handle.c map_read.c math_01.c win_handle.c win_hotkey.c win_mouse.c
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# Includes
INCLUDES    = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

# MLX Flags
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11

# Math Flags
MATH_FLAGS  = -lm

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(BOLD)$(YELLOW_BR)\n   Building $(NAME)\n$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MATH_FLAGS) -o $(NAME)
	@echo "$(BOLD)$(GREEN_BR)$(NAME) is ready!$(DEF_COLOR)"

$(LIBFT):
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⣋⣉⡙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠮⡞⠁⠀⠈⢢⠷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⢠⢤⣇⠀⡇⠀⠀⠀⢸⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⡏⢰⠙⠚⢧⣀⢀⣠⠞⠓⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⡸⠀⡎⠀⣀⡤⠏⠉⠧⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⢠⠃⢰⡵⠊⠁⠀⠀⠀⠀⠀⠈⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⢸⡀⠀⣀⡠⡆⠀⠀⠀⠀⠀⣆⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⡇⠀⠀⠀⠀⠀⡏⢣⡀⠘⣄⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢸⠀⠙⢤⡈⢦⡀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⠀⢠⠖⣒⣶⠖⠒⠒⠒⠲⠷⣒⠒⠒⠒⠒⣺⣶⠖⠒⠓⢤⣹⠶⣒⠲⡄⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⠀⢠⠏⣞⣟⠉⠀⣖⠒⣲⠀⠀⠈⣳⠀⠀⡎⡞⠉⠀⣖⢒⣢⠀⠀⠈⡇⠹⡄⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⢠⠏⠀⠘⠪⢅⣀⣀⠉⣀⣀⡠⠔⠁⠀⠀⠙⠮⣇⣀⣀⠉⣀⣀⡤⠖⠁⠀⠹⡄ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⡟⠒⠒⠒⠒⠒⠒⠓⠛⠚⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠛⠛⠒⠒⠒⠒⠒⠒⢻ $(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⡇$(DEF_COLOR)   $(BOLD)$(BLUE_BR)Getting libft ready!$(DEF_COLOR)     $(BOLD)$(GREEN_BR)⢸$(DEF_COLOR)"
	@echo "$(BOLD)$(GREEN_BR)⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸$(DEF_COLOR)"
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX):
	@echo "$(BOLD)$(PINK_BRR)\n  Building minilibx...     $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⢤⡀⠀             $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⢀⠎⠀⠀⠀⠘⣦⠀            $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⢠⣾⡖⢦⣰⣿⢲⠸⡇⠀⠀⠀        $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⢨⠻⢷⣟⠙⠿⠞⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)       ⠀⠀⠀⠀⠀⢸⠦⠤⠷⠶⠶⠂⠀⢸⠀⠀⠀⠀⠀⠀⢀⢀⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⡆⡄⢸⠀⠀⠀⠀⠀⢠⠃⢸⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⡇⡇⢸⣇⡀⠀⠀⡠⠁⢠⠃⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⣸⠃⢻⠈⠈⠉⢙⣳⣥⣄⣀⠔⠀ $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠸⡆⠀⠀⠰⣧⣶⠌⠂⠀⠀⠉⠁⠀⠀⠉⠳⡄⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⠹⢦⣀⣀⣀⡀⠀⢀⣀⣀⡀⠀⢀⣀⡠⠚⠀⠀$(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠉⡹⠉⠉⠉⠉⢉⠇⢠⠃⠀     $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠰⡉⠑⠁⢠⠃⠀⠀⣟⠓⠋⢠⠃⠀      $(DEF_COLOR)"
	@echo "$(BOLD)$(YELLOW_BR)      ⠀⠀⠀⠀⠀⠀⠀⠈⠛⠒⠁⠀⠀⠀⠈⠓⠒⠁⠀       $(DEF_COLOR)"
	@$(MAKE) -s -C $(MLX_DIR)

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@$(RM) $(OBJ_DIR)
	@echo "$(UNDERLINE)$(PINK_BR)Cleaned object files$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(UNDERLINE)$(ORANGE)Removed all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

