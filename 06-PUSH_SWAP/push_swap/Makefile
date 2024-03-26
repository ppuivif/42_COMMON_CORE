CC=clang
CFLAGS=-Wall -Werror -Wextra -g
NAME1=push_swap
NAME2=checker
SOURCES1=push_swap.c ft_sort_params.c \
		build_and_free_linked_list.c \
		utils_1.c utils_2.c \
		functions_to_control_stacks.c \
		sort_stack.c best_sort.c

SOURCES2=checker.c ft_sort_params.c \
		build_and_free_linked_list.c \
		utils_1.c utils_2.c \
		functions_to_control_stacks.c \
		sort_stack.c best_sort.c \
		GNL/get_next_line.c GNL/get_next_line_utils.c

OBJECTS1=$(SOURCES1:.c=.o)

OBJECTS2=$(SOURCES2:.c=.o)

all: $(NAME1)

bonus: $(NAME2)

$(NAME1) : $(OBJECTS1)
				cd LIBFT && make && cd ..
				cd FT_PRINTF && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS1) LIBFT/libft.a FT_PRINTF/libftprintf.a -o $@
				@clear

$(NAME2) : $(OBJECTS2)
				cd LIBFT && make && cd ..
				cd FT_PRINTF && make && cd ..
				$(CC) $(CFLAGS) $(OBJECTS2) LIBFT/libft.a FT_PRINTF/libftprintf.a -o $@
				@clear

%.o : %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean :
				cd LIBFT && make clean && cd ..
				rm -rf $(OBJECTS1)
				rm -rf $(OBJECTS2)

fclean : clean
				rm -rf $(NAME1)
				rm -rf $(NAME2)

re : fclean all

.PHONY: all clean fclean re bonus
