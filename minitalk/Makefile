
CFILES = server.c client.c server_bonus.c client_bonus.c	
OBJS = ${CFILES:.c=.o}

SERVER_NAME = server
CLIENT_NAME = client
SERVER_NAME_bonus = server_bonus
CLIENT_NAME_bonus = client_bonus

CFLAGS = -Wall -Wextra -Werror

PRINTF_PATH = ft_printf
PRINTF_LIB = libftprintf.a

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): server.o $(PRINTF_PATH)/$(PRINTF_LIB)
	cc $(CFLAGS) -o $(SERVER_NAME) server.o -L$(PRINTF_PATH) -lftprintf

$(CLIENT_NAME): client.o $(PRINTF_PATH)/$(PRINTF_LIB)
	cc $(CFLAGS) -o $(CLIENT_NAME) client.o -L$(PRINTF_PATH) -lftprintf


$(PRINTF_PATH)/$(PRINTF_LIB):
	make -C $(PRINTF_PATH)

bonus: $(SERVER_NAME_bonus) $(CLIENT_NAME_bonus)

$(SERVER_NAME_bonus): server_bonus.o $(PRINTF_PATH)/$(PRINTF_LIB)
	cc $(CFLAGS) -o $(SERVER_NAME_bonus) server_bonus.o -L$(PRINTF_PATH) -lftprintf

$(CLIENT_NAME_bonus): client_bonus.o $(PRINTF_PATH)/$(PRINTF_LIB)	
	cc $(CFLAGS) -o $(CLIENT_NAME_bonus) client_bonus.o -L$(PRINTF_PATH) -lftprintf

clean:
	rm -f $(OBJS)
	make -C $(PRINTF_PATH) clean


fclean: clean
	make -C $(PRINTF_PATH) fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -f $(SERVER_NAME_bonus) $(CLIENT_NAME_bonus)

re: fclean all

.PHONY: all clean fclean re
