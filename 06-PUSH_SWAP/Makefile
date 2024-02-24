CC=clang
CFLAGS=-Wall -Werror -Wextra -g
NAME=push_swap
SOURCES=push_swap.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
				cd LIBFT && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a -o $@
				@clear

%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean :
				rm -rf $(OBJECTS)

fclean : clean
				rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
