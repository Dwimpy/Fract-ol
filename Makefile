# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/02/27 14:56:39 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			= fractol
INCLUDE			= -I ./include/ -I ./libft-printf/include/ -I ./MLX42/include/MLX42/
DSYM			= ./fractol.dSYM
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft-printf
LIBFT_LIB		= ./libft-printf/libft.a
MAIN_FILE		= main.c
MLX_LIB			= ./MLX42/build
GLFW_LIB		= ./glfw/build/src
GLFW_BUILD		= ./glfw/build
MLX_BUILD		= ./MLX42/build
NORM_INCLUDE	= ./include

# Compiler
CC			= cc -Wall -Werror -Wextra
CFLAGS		= -Ofast -march=nocona -flto
ASAN		= #-fsanitize=address -g3
#CFLAGS		= -Ofast -march=native -flto #-fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit
LDLFLAGS	= -lft -L $(LIBFT_FOLDER)  -lmlx42 -L $(MLX_LIB) -L $(GLFW_LIB) -lglfw3 -lm
#LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/build -ldl -lglfw -pthread

#Archive and Remove
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources
SRCS	=	color_utils.c complex_number_set.c complex_operations.c complex_operators.c  \
			complex_printing.c data_animation.c data_animation_translation.c data_flags.c  \
			data_fractals_init.c data_init_args.c data_movement.c data_pixel_map.c  \
			data_render_translation.c data_renderer.c data_renderer_init.c data_renderer_julia_init.c  \
			data_viewport_translation.c fractal_distance_estimations.c fractal_distances.c fractal_equations.c  \
			fractal_nodes.c fractal_swap.c fractals_list.c fractol.c  \
			fractol_args_options.c fractol_julia_args.c fractol_parser.c hooks.c  \
			redraw_julia.c renderer.c viewport.c viewport_zoom.c  window_manager.c 

# Objects
OBJS	= 	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Rules
all:	deps	libft	$(NAME)

$(NAME): $(OBJS) | $(OBJ_DIR)
	@$(CC) $(INCLUDE) $(FRAMEWORK) $(ASAN) $(OBJS) $(MAIN_FILE) -o $@ -lm $(LDLFLAGS) 
	@echo "$(YELLOW)Fractol$(DEF_COLOR) $(CYAN)done.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@ $(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

deps:
	@chmod +x ./install_dependencies.sh
	@echo "$(YELLOW)Installing dependencies..$(DEF_COLOR)"
	@./install_dependencies.sh

libft:
			@make all -C $(LIBFT_FOLDER) -s

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)Fractol$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIBFT_FOLDER)
			@rm -rdf $(GLFW_BUILD)
			@rm -rdf $(MLX_BUILD)
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all

relibft:
			@make re -C $(LIBFT_FOLDER)

bonus:	libft	mlx	$(NAME)

.PHONY:		all mlx relibft libft clean fclean re norm
