
NAME:=	pipex
SRC:= 	pipex.c utils.c parser.c
		
OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
#FLAGS+= -g3 -fsanitize=address

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	make re -C lib/libft
	make re -C lib/ft_printf
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) lib/ft_printf/ft_printf.a lib/libft/libft.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f pipex
re: fclean all