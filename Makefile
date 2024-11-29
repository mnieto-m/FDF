NAME = fdf
CC = cc
RM = rm 
RMFLAGS = -rf
CFLAGS = -Wall -Werror -Wextra -g3
R = r
INCLUDE = fdf.h

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIBFT = ./Libft/bin/libft.a
LIBFT_PATH = ./Libft/




all: ${NAME}

${NAME}:	${OBJ} ${INCLUDE} ${LIBFT}
	$(CC) $(CFLAGS) ${OBJ} -o ${NAME} ${LIBFT}

$(LIBFT) : 
			$(MAKE) -C $(LIBFT_PATH)
 
clean:
	$(RM) $(RMFLAGS) ${OBJ} $(LIBFT)

fclean: clean 
	$(RM) $(RMFLAGS) $(NAME) $(printf) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
