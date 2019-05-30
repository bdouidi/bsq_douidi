NAME = libft.a

SRC = ft_putchar.c ft_strlen.c strcmp.c ft_putstr.c ft_swap.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	ar rc $(NAME) $(SRC)
	ranlib $(NAME)

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	


