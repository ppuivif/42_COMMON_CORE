CC = c++

CFLAGS = -Wall -Werror -Wextra

NAME = megaphone

SOURCES = 	sources/megaphone.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
		@clear

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
