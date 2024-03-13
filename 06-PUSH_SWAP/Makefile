CC=clang
CFLAGS=-Wall -Werror -Wextra -g
NAME=push_swap
SOURCES=push_swap.c ft_sort_params.c \
		build_and_free_linked_list.c \
		utils_1.c utils_2.c utils_3.c \
		functions_to_control_stacks.c \
		sort_stack.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
				cd LIBFT && make && cd ..
				cd FT_PRINTF && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a FT_PRINTF/libftprintf.a -o $@
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
