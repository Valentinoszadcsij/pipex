
NAME:=	libft.a
SRC:=	ft_split.c ft_strlen.c ft_strnstr.c ft_strjoin.c ft_putstr_fd.c ft_strchr.c ft_strrchr.c

OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f libft.a
re: fclean all