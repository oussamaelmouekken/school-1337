NAME = push_swap
NAMEB = checker
CC = cc


CFILES =  sort_2.c sort_3_5.c check_error.c nbr.c push_to_b.c push_to_a.c arr.c push_swap_utils.c push_swap.c push.c reverse_rotate.c  swap.c rotate.c 
CFILESB = get_next_line.c get_next_line_utils.c checker.c nbr.c arr.c push_swap_utils.c push.c reverse_rotate.c swap.c rotate.c check_error.c check_error1.c
OBJ = ${CFILES:.c=.o}
OBJB =  ${CFILESB:.c=.o}
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(NAMEB)
 $(NAMEB): $(OBJB)
	$(CC) $(CFLAGS)  -o $(NAMEB) $(OBJB)


clean:
	rm -f $(OBJ) $(OBJB) 

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY : all  clean fclean re bonus