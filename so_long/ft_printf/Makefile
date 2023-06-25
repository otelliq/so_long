NAME = libftprintf.a

SRC = ft_printf.c ft_putnbrr.c ft_formatchooser.c ft_putcharr.c ft_putstrr.c ft_putunsignedd.c ft_puthexx.c
OBJ = ft_printf.o ft_putnbrr.o ft_formatchooser.o ft_putcharr.o ft_putstrr.o ft_putunsignedd.o ft_puthexx.o
all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc -Wall -Werror -Wextra -c $(SRC)

clean:
	rm -f *.o
fclean: clean
	rm -f libft.a
re: fclean all
