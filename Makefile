NAME = server
CLIENT = client
FLAGS = -Wall -Werror -Wextra -O3 -g
SRV_SRC = server.c 
CLT_SRC =  client.c ft_atoi.c
O = $(SRC:.c=.o)

all: $(NAME) $(CLIENT)

$(NAME):
	@gcc $(SRV_SRC) $(FLAGS) -o $(NAME)

$(CLIENT):
	@gcc $(CLT_SRC) $(FLAGS) -o $(CLIENT)

clean:
	echo "cleaning..."

fclean: clean
	@rm -f $(NAME) $(CLIENT)

re:	fclean all