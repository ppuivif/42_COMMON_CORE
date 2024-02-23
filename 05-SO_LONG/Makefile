CC= clang
CFLAGS=-Wall -Werror -Wextra -g
MACROLIBXFLAGS= -lSDL2
NAME=so_long
SOURCES=main_display.c check_validity_1.c check_validity_2.c \
			check_validity_3.c import_map.c \
			create_image_1.c create_image_2.c create_image_3.c \
			events.c move_1.c move_2.c anim_char.c \
			init_struct.c destroy.c free.c \
			main.c

SOURCES+=GNL/get_next_line.c GNL/get_next_line_utils.c

OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		cd LIBFT && make && cd ..
		cd MacroLibX && make && cd ..
		$(CC) $(CFLAGS) $(OBJECTS) LIBFT/libft.a $(MACROLIBXFLAGS) MacroLibX/libmlx.so -o $@
		@clear
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
