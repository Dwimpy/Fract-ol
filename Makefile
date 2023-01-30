# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/01/30 18:51:05 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= fractol
INCLUDE			= -I include/
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft
LIBFT_LIB		= ./libft/libft.a
NORM_INCLUDE	= ./include
MAIN_FILE		= main.c
# Compiler

CC			= cc
CFLAGS		= -Ofast -g3 -march=nocona -flto  #-fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
#CFLAGS		= -O2 -march=native -flto #-fsanitize=address -g3 #-g3 -Wall -Werror -Wextra -g3 #
LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/  -L ~/.brew/opt/glfw/lib/ -lglfw -lm
#LDLFLAGS	= -lft -L ./libft/ -lmlx42 -L ./MLX42/ -ldl -lglfw
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

SRCS	=	$(wildcard $(SRC_DIR)/*.c)
OBJS	= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all:	libft	$(NAME)

$(NAME): $(OBJS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE)  $(OBJS) $(MAIN_FILE) -o $@ -lm $(LDLFLAGS)
	@echo "$(YELLOW)Fractol$(DEF_COLOR) $(CYAN)built successfully.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA)Compiling:$(DEF_COLOR) $<."
	@ $(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft:
			@make all -C $(LIBFT_FOLDER) -s

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@$(RM) -rdf $(DSYM)
			@echo "$(YELLOW)Fractol$(DEF_COLOR) $(CYAN)successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@make fclean -C $(LIBFT_FOLDER)
			@$(RM) -f $(NAME)
			@echo "$(YELLOW)All$(DEF_COLOR) $(CYAN)objects successfully cleaned!$(DEF_COLOR)"

re:			fclean all

relibft:
			@make re -C $(LIBFT_FOLDER)

bonus:	libft	$(NAME)

norm:
			@norminette $(SRC_DIR) $(NORM_INCLUDE) | grep -v OK
		
.PHONY:		all relibft libft clean fclean re norm