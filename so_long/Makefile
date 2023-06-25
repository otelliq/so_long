#Define the compiler
CC = cc

# Define the flags to pass to the compiler
# CFLAGS = -Wall -Wextra -Werror

# Define the source files for the so_long executable
SRC = movements.c movements_utils.c rendering.c so_long.c so_long_utils.c so_long_utils2.c path_check.c map.c map_reader.c map_checker.c ./ft_printf/ft_printf.c ./ft_printf/ft_printf_utilc.c ./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c
# Define the object files for the so_long executable, generated from the source files
OBJ = $(SRC:.c=.o)

# Define the name of the so_long executable to be generated
NAME = so_long

# Define the default target to be built
all: $(NAME)

# Rule to generate the so_long executable from the object files
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c,%.o,$<)

# Clean target to remove generated files
clean:
	rm -f $(OBJ) map_utils.o map_utils1.o map_utils2.o so_long.o 

# Fclean target to remove executable files and perform clean
fclean: clean
	rm -f $(NAME)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean
