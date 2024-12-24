# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: annavm <annavm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 21:47:07 by annavm            #+#    #+#              #
#    Updated: 2024/12/24 20:05:51 by annavm           ###   ########.fr        #
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
NAME = fdf
UNAME = $(shell uname -s)
INC_DIR     = incs
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address 
HEADERS = $(wildcard incs/*.h)
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
RM = @rm -rf

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

FILES = fdf fig_feature free_exit graphics_prim key_board \
		key_mouse loading_bar map_color map_drawing \
		map_handle map_points map_read map_render \
		map_size math_angle math_geom math_move \
		put_pixel setup_hooks switch_color win_handle

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./obj/
OBJ_DIRS = $(OBJS_DIR)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

INCFLAGS = $(INCLUDES)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCFLAGS)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@echo "$(BOLD)$(YELLOW_BR)\n   Building $(NAME)\n$(DEF_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -lm $(LIBFT_LIB)
	@echo "$(BOLD)$(GREEN_BR)$(NAME) is ready!$(DEF_COLOR)"
	
$(LIBFT_LIB):
	@echo "$(BOLD)$(BLUE_BR)Getting libft ready!$(DEF_COLOR)"	
	@make -s -C $(LIBFT_DIR)


$(MLX_LIB):
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
	@make --quiet -C $(MLX_DIR)

clean:
	$(RM) $(OBJS_DIR) $(NAME)
	@echo "$(UNDERLINE)$(PINK_BR)Cleaned object files$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(UNDERLINE)$(ORANGE)Removed all binaries$(DEF_COLOR)"

re: clean $(NAME)

fre: fclean $(NAME)

norm: $(NAME)
	@norminette $(SRCS) $(HEADERS)

.PHONY: all clean fclean re fre norm
