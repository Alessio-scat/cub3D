.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re sanitize

NAME					= cub3D

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= cub3D.h

DIR						= src/
SRC			 			= main.c \
							parsing/check_map/check_extension.c \
							parsing/check_map/check_wall.c \
							parsing/check_map/utils_check_wall.c \
							parsing/check_map/check_character.c \
							parsing/check_map/check_color.c \
							parsing/check_map/check_map.c \
							parsing/parsing.c \
							parsing/parse_elements.c \
							parsing/init.c \
							parsing/parse_map.c \
							parsing/utils_parse.c \
							utils/free.c \
							utils/free_mlx.c \
							utils/utils.c \
							raycasting/window.c \
							raycasting/move.c \
							raycasting/utils_raycasting.c \
							raycasting/init.c \
							raycasting/minimap.c \
							raycasting/texture.c \
							raycasting/gun.c \
							raycasting/mouse.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) $(LIB_DIR) Makefile
						@mkdir -p $(@D)
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)
						@echo "$(GREEN)[✓] $(NAME) created !$(DEFAULT)"

sanit :					$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(CFLAGS) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

lib:
						@make -C $(LIB_DIR)


minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)
						@${RM} $(BUILD_DIR)
						@echo "$(YELLOW)[-] object files deleted !$(DEFAULT)"

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@echo "$(RED)[x] all deleted !$(DEFAULT)"

re:						fclean all
						$(MAKE) all

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m