
NAME:=	pipex
SRC:= 	pipex.c utils.c
		
OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
#FLAGS+= -g3 -fsanitize=address

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
#make -C lib/get_next_line
#make re -C lib/ft_printf
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f pipex
re: fclean all