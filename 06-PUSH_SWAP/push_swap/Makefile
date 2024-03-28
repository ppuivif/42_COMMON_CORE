CC=clang
CFLAGS=-Wall -Werror -Wextra -g
NAME1=push_swap
NAME2=checker
SOURCES1=push_swap.c \
		build_and_sort_arrays_1.c build_and_sort_arrays_2.c \
		free_arrays.c check_parameters_in_str.c check_parameters_in_arrays.c\
		build_linked_list.c free_linked_list.c \
		functions_to_control_stacks_1.c functions_to_control_stacks_2.c \
		sort_stack.c sort_stack_utils.c

SOURCES2=checker.c \
		build_and_sort_arrays_1.c build_and_sort_arrays_2.c \
		free_arrays.c check_parameters_in_str.c check_parameters_in_arrays.c\
		build_linked_list.c free_linked_list.c \
		functions_to_control_stacks_1.c functions_to_control_stacks_2.c \
		sort_stack.c sort_stack_utils.c \
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
