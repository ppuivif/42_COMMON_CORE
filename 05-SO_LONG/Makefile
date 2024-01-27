CC= clang
CFLAGS=-Wall -Werror -Wextra -g
MACROLIBXFLAGS= -lSDL2
NAME=so_long
SOURCES=so_long.c import_map.c GNL/get_next_line.c GNL/get_next_line_utils.c main.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		cd LIBFT && make && cd ..
		cd MacroLibX && make && cd ..
		$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a $(MACROLIBXFLAGS) MacroLibX/libmlx.so -o $@
		@if [ $$? -eq 0 ]; then \
			echo "\033[32;1mCompilation successful!\033[0m"; \
		fi


%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJECTS)

fclean : clean 
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re