CC=cc
CFLAGS=-Wall -Wextra -Werror -g
NAME=libft.a
HEADER=libft.h
SOURCES= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c\
		ft_strlen.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strcpy.c \
		ft_strlcpy.c ft_strcat.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strcmp.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lst_dc_new.c ft_lst_dc_add_back.c ft_lst_dc_add_front.c ft_lst_dc_last.c \
		ft_lst_dc_delone.c ft_lst_dc_print.c ft_lst_dc_size.c ft_lst_dc_is_sorted.c
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	       
clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
