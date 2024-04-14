CC=gcc
FLAGS=-Wall -Werror -Wextra -g #-g to delete
NAME=pipex
#HEADERS=includes/pipex.h
SRCS=pipex.c parsing_files.c parsing_cmd.c \
	execution.c error_and_free.c init_struct.c
OBJECTS=$(SRCS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJECTS)
						cd LIBFT && make && cd ..
						$(CC) $(FLAGS) $(OBJECTS) LIBFT/libft.a -o $@
						@clear

%.o : %.c
						$(CC) $(FLAGS) -c $< -o $@

clean :
				cd LIBFT && make clean && cd ..
				rm -rf $(OBJECTS)

fclean : clean
				cd LIBFT && make fclean && cd ..
				rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

