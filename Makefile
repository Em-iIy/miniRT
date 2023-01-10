# ----------------------------------------Name
NAME = minirt

# ----------------------------------------FILES
FILES_SRCS =	main.c \
				vect3.c \
				vect3_add.c \
				vect3_substract.c \
				vect3_multiply.c \
				vect3_print.c \
				vect3_dot_product.c \
				quadratic_formula.c \
				sphere.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/
DIR_LIBFT = ./src/libft

vpath %.c $(DIR_SRCS) $(DIR_OBJS)
vpath %.c $(DIR_SRCS)collision/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)vect3_math/ $(DIR_OBJS)


# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinc -I$(DIR_LIBFT)

# ----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)/libft.a

# ----------------------------------------Debug
ifdef WITH_ADDRESS
CFLAGS += -g -fsanitize=address
endif


# ----------------------------------------Making
all:
	@$(MAKE) $(NAME) -j4

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm $(INC) $(LIBFT)

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "libft made!"

# ----------------------------------------Debug
address:
	$(MAKE) re WITH_ADDRESS=1

# ----------------------------------------Cleaning
clean:
	make -C $(DIR_LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re