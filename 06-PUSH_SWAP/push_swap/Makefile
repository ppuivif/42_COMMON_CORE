CC=clang
CFLAGS=-Wall -Werror -Wextra -g
#NAME=push_swap
NAME2=push_swap_bonus
SOURCES=push_swap.c ft_sort_params.c \
		build_and_free_linked_list.c \
		utils_1.c utils_2.c utils_3.c \
		functions_to_control_stacks.c \
		sort_stack.c best_sort.c \
		checker.c

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME2)

#bonus: $(NAME2)

#$(NAME) : $(OBJECTS)
#				cd LIBFT && make && cd ..
#				cd FT_PRINTF && make && cd ..
#				$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a FT_PRINTF/libftprintf.a -o $@
#				@clear

$(NAME2) : $(OBJECTS)
				cd LIBFT && make && cd ..
				cd FT_PRINTF && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a FT_PRINTF/libftprintf.a GNL/get_next_line.h -o $@
				@clear

%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean :
				cd LIBFT && make clean && cd ..
				rm -rf $(OBJECTS)

fclean : clean
#				rm -rf $(NAME)
				rm -rf $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus
