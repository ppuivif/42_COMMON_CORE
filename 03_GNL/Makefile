# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppuivif <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 16:08:06 by ppuivif           #+#    #+#              #
#    Updated: 2023/12/08 16:29:49 by ppuivif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -g
NAME=get_next_line.a
HEADER=get_next_line.h
SOURCES= get_next_line.c get_next_line_utils.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$NAME : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean :
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


