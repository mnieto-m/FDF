NAME = fdf

# Variables generales
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm
RMFLAGS = -rf
MKDIR = mkdir -p
INCLUDE = -I ${INCLUDE_DIR} -I $(LIBMLX)/include
# Directorios

LIBFT_DIR = Libft/
LIBFT_BIN = Libft/bin/
LIBFT_NAME = $(LIBFT_BIN)libft.a
SRC_DIR = src/
OBJ_DIR = bin/obj/
BIN_DIR = bin/
INCLUDE_DIR = include/
LIBMLX	= ./MLX42

#Files
FILES = fdf \
		init_map \
		parse/check_argv \
		parse/checkfile_fdf \
		parse/read_map \
		error/ft_error \
		utils/ft_atoi_base \
		mlx/hooks \
		mlx/ft_print_img \
		matrix/isometric \
		matrix/matrix_op \
		matrix/matrix_projection \
		structs/tmap \
		structs/tnode \
		structs/tview


# FILES_ADD
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# 1ª RULE
all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Comp bin
$(NAME): $(OBJ) $(LIBFT_NAME)
	$(MKDIR) $(BIN_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT_NAME) -o $(NAME) $(LIBS)

# Comp .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
# Compilar la libft
$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

# clean OBJ
clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(RM) $(RMFLAGS) $(LIBMLX)/build

# clean binary OBJ
fclean: clean
	$(RM) $(RMFLAGS) $(BIN_DIR) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilar todo
re: fclean all 

.PHONY: all, clean, fclean, libmlx
