#=================== NAME ===================#

NAME = iter

#================ COMPILATOR ================#

CC = c++

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -std=c++98 \
	 -Iincludes

#============= MANDATORY SOURCES ============#

SRCS =  sources/main.cpp

#============ TRANSFORM .c TO .o ============#

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#============ Colors ========================#

normal = '\033[0m'
green = '\033[0;32m'

#================ UTILS PART ================#

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(green)"Executable is ready"$(normal)

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 
