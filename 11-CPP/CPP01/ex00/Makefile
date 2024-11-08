# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:27:08 by ppuivif           #+#    #+#              #
#    Updated: 2024/11/07 18:13:03 by ppuivif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== NAME ===================#

NAME = zombie

#================ COMPILATOR ================#

CC = g++

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -Iincludes -g

#============= MANDATORY SOURCES ============#

SRCS =  sources/main.cpp \
		sources/Zombie.cpp \
		sources/newZombie.cpp \
		sources/randomChump.cpp \

#============ TRANSFORM .c TO .o ============#

OBJS=$(SRCS:.cpp=.o)

#============ Colors ========================#

white='\033[1;37m'
dark_green='\033[0;32m'

#================ UTILS PART ================#

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(dark_green)"Executable is ready"

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 
