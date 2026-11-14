CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
AR = ar rcs
SOURCES = $(shell find . -name "*.c" ! -name "main.c")
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
