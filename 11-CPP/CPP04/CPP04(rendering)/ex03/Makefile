# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:27:08 by ppuivif           #+#    #+#              #
#    Updated: 2025/01/07 15:13:16 by ppuivif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== NAME ===================#

NAME = amateria

#================ COMPILATOR ================#

CC = c++

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -std=c++98 \
	 -Iincludes

#============= MANDATORY SOURCES ============#

SRCS =  sources/main.cpp \
		sources/AMateria.cpp \
		sources/Ice.cpp \
		sources/Cure.cpp \
		sources/Character.cpp \
		sources/MateriaSource.cpp 

#============ TRANSFORM .c TO .o ============#

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#============ Colors ========================#

white = '\033[1;37m'
dark_green = '\033[0;32m'

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
