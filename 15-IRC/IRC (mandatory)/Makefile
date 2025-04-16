#=================== NAME ===================#

NAME = ircserv

#================ COMPILATOR ================#

CC = c++

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -g -std=c++98 \
	 -Iincludes

#============= MANDATORY SOURCES ============#

SRCS =  sources/main.cpp \
		sources/Server.cpp \
		sources/Client.cpp \
		sources/ReceivedData.cpp \
		sources/receivedDataUtils.cpp \
		sources/commands/passHandle.cpp \
		sources/commands/nickHandle.cpp \
		sources/commands/kickHandle.cpp \
		sources/commands/userHandle.cpp \
		sources/commands/inviteHandle.cpp \
		sources/commands/modeHandle.cpp \
		sources/commands/topicHandle.cpp \
		sources/commands/quitHandle.cpp \
		sources/commands/privmsgHandle.cpp \
		sources/commands/unknownHandle.cpp \
		sources/commands/partHandle.cpp \
		sources/commands/joinHandle.cpp \
		sources/Channel.cpp \

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
