# ----------------------------------------Name
NAME = minirt

# ----------------------------------------FILES
FILES_SRCS =	main.c \
				error.c \
				vect3.c \
				vect3_print.c \
				vect3_dot_product.c \
				vect3_cross_product.c \
				vect3_abs.c \
				vect3_normalize.c \
				fmin_pos.c \
				quadratic_formula.c \
				get_collision.c \
				sphere.c \
				plane.c \
				cylinder.c \
				circle.c \
				ray.c \
				object_utils.c \
				objects.c \
				init_scene.c \
				check_inside.c \
				add_camera.c \
				add_lights.c \
				get_colour.c \
				get_phong.c \
				lighting_utils.c \
				parse_rgb.c \
				parse_atod.c \
				parse_coords.c \
				parse_direction.c \
				parse_object.c \
				parse_line.c \
				parse_file_name.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/
DIR_LIBFT = ./src/libft
DIR_MLX = ./src/MLX42

vpath %.c	$(DIR_SRCS) \
			$(DIR_SRCS)collision/ \
			$(DIR_SRCS)vect3_math/ \
			$(DIR_SRCS)parser/ \
			$(DIR_SRCS)lighting/ \


# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
# not optimized	: ./minirt rt_files/cake.rt  68.19s user 0.04s system 99% cpu 1:08.27 total
# -O3			: ./minirt rt_files/cake.rt  17.32s user 0.03s system 99% cpu 17.386 total
# -Ofast		: ./minirt rt_files/cake.rt  17.05s user 0.03s system 99% cpu 17.119 total
MLXFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
INC = -Iinc -I$(DIR_LIBFT) -I$(DIR_MLX)/include

# ----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)/libft.a
MLX = $(DIR_MLX)/libmlx42.a

# ----------------------------------------Debug
ifdef WITH_ADDRESS
CFLAGS += -g -fsanitize=address
endif

ifdef WITH_UNDEFINED
CFLAGS += -g -fsanitize=undefined
endif


# ----------------------------------------Making
all:
	@$(MAKE) $(NAME) -j4

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm $(INC) $(LIBFT) $(MLX) $(MLXFLAGS)

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "libft made!"

$(MLX):
	make -C $(DIR_MLX)

# ----------------------------------------Norminette
norme:
	norminette ./inc
	norminette ./src/collision
	norminette ./src/libft
	norminette ./src/lighting
	norminette ./src/parser
	norminette ./src/vect3_math
	norminette ./src/error.c ./src/main.c

# ----------------------------------------Debug
address:
	$(MAKE) re WITH_ADDRESS=1

undefined:
	$(MAKE) re WITH_UNDEFINED=1

# ----------------------------------------Cleaning
clean:
	make -C $(DIR_LIBFT) clean
	make -C $(DIR_MLX) clean
	@rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	make -C $(DIR_MLX) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re