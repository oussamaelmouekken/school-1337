NAME = so_long
CC = cc
CFILES =  so_long.c get_next_line.c get_next_line_utils.c  map.c map1.c fllod_file.c move.c map_image.c move1.c check_map.c
OBJ = ${CFILES:.c=.o}
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
FLAGS = -lmlx -framework OpenGL -framework AppKit
PRINTF = ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(FLAGS) -L$(PRINTF) -lftprintf -o $(NAME)

clean:
	rm -f $(OBJ)
	make  clean -C $(PRINTF)

fclean: clean
	rm -f $(NAME) 
	make fclean -C $(PRINTF)

re: fclean all

.PHONY : all  clean fclean re