
#include "Server.hpp"

int	checkPortNumber(char * portNumber){

	int result = std::atoi(portNumber);
	
	if (result < 0 || result > 65535)
		return (-1);
	return (result);
}

int	checkPassword(char * password){

	int i = 0;

	if (password[i] == 0)
		return (1);

	while (password[i]){
		if (password[i] <= 32 || password[i] == 127)
			return (1);
		i++;
	}
	return (0);
}

int	checkArguments(int argc, char **argv, int *portNumber, std::string *password){
	
	if (argc != 3){
		std::cout << BOLD_RED <<"Error\nusage : ./ircserv <IP address> <password>" << NORMAL << std::endl;
		return (1);
	}
	
	*portNumber = checkPortNumber(argv[1]);
	if (*portNumber == -1){
		std::cout << BOLD_RED << "Error : IP address must be included between 0 and 65535" << NORMAL << std::endl;
		return (1);
	}
	
	if (checkPassword(argv[2])){
		std::cout << BOLD_RED << "Error : password is not allowed" << NORMAL << std::endl;
		return (1);
	}

	*password = argv[2];

	return (0);
}

int	main(int argc, char **argv){

	int			portNumber;
	std::string	password;

	if (checkArguments(argc, argv, &portNumber, &password))
		return (1);

	Server	server(portNumber, password);
	
	signal(SIGINT, Server::signalHandler);
	signal(SIGQUIT, Server::signalHandler);

	if (server.createServerSocket())
		return (1);
		
	if (server.runServerSocket())
		return (1);
	
	server.startServer();
	server.clearServer();
	
	std::cout << GREEN << "Server is closed" << NORMAL << std::endl;
	return (0);
}