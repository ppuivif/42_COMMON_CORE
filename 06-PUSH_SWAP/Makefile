CC=clang
CFLAGS=-Wall -Werror -Wextra -g
NAME=push_swap
SOURCES=push_swap.c ft_sort_params.c linked_list.c \
		utils_1.c utils_2.c utils_3.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
				cd LIBFT && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a -o $@
				@clear

%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean :
				cd LIBFT && make clean && cd ..
				rm -rf $(OBJECTS)

fclean : clean
				rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
