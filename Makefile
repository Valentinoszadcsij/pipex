
NAME:=	pipex
SRC:= 	pipex.c utils.c parser.c ft_split_with_quotes.c procs.c
		
OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=address

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	make re -C lib/libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) lib/libft/libft.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f pipex
re: fclean all