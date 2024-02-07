CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
NAME=ft_lst
SOURCES=main.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@

%.c : %.o
	$(CC) $(FLAGS) -c $< -o $@

clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re