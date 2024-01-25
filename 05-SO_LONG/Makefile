CC= clang
CFLAGS=-Wall -Werror -Wextra -I./MacroLibX/includes -g
MACROLIBXFLAGS= -lSDL2
NAME=so_long
SOURCES=so_long.c utils.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		cd MacroLibX && make && cd ..
		$(CC) $(CFLAGS) $(OBJECTS) $(MACROLIBXFLAGS) MacroLibX/libmlx.so -o $@
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