CC=gcc
FLAGS=-Wall -Werror -Wextra
NAME=pipex
SRCS=pipex.c parsing_files.c parsing_cmd_1.c parsing_cmd_2.c \
	execution.c error_and_free.c init_struct.c \
	pipex_utils_1.c pipex_utils_2.c pipex_utils_3.c

OBJECTS=$(SRCS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJECTS)
						$(CC) $(FLAGS) $(OBJECTS) -o $@
						@clear

%.o : %.c
						$(CC) $(FLAGS) -c $< -o $@

clean :
				rm -rf $(OBJECTS)

fclean : clean
				rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

