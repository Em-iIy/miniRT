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
				quadratic_formula.c \
				sphere.c \
				plane.c \
				cylinder.c \
				circle.c \
				ray.c \
				object_utils.c \
				objects.c \
				init_scene.c \
				add_camera.c \
				add_lights.c \
				get_colour.c \
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

vpath %.c $(DIR_SRCS) $(DIR_OBJS)
vpath %.c $(DIR_SRCS)collision/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)vect3_math/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)parser/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)lighting/ $(DIR_OBJS)


# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -I $(DIR_MLX)/include
# MLXFLAGS += -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
INC = -Iinc -I$(DIR_LIBFT) $(MLXFLAGS)

# ----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)/libft.a
MLX = $(DIR_MLX)/libmlx42.a

# ----------------------------------------Debug
ifdef WITH_ADDRESS
CFLAGS += -g -fsanitize=address
endif


# ----------------------------------------Making
all:
	@$(MAKE) $(NAME) -j4

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm $(INC) $(LIBFT) $(MLX) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "libft made!"

$(MLX):
	make -C $(DIR_MLX)

# ----------------------------------------Debug
address:
	$(MAKE) re WITH_ADDRESS=1

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