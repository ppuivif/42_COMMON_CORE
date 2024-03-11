CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
NAME=ft_lst
SOURCES=main.c ft_lstnew.c \
		ft_lst_dc_last.c \
		ft_lst_dc_add_front.c \
		ft_lst_dc_add_back.c \
		ft_lst_dc_size.c \
		ft_lst_dc_print.c \
		ft_lst_dc_delone.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re