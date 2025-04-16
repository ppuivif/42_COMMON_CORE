
#include "ReceivedData.hpp"

static bool	isNicknameAvailable(Client *client){

	if (client->getClientIsAvailableNickname() == true)
		return (true);
	else{
//		std::cout << BOLD_RED << "nickname has already been used" << NORMAL << std::endl; //to comment
		std::string message = ERR_NICKNAMEINUSE(clientStr, client->getClientNickname());
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (false);
	}
}

int	ReceivedData::userHandle(std::vector<std::string> const & data, Server *server, Client *client){

	(void)server;
	std::string clientStr;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

//	dataDisplaying(data); //to comment

	if (client && verifyClientCorrectPassword(client) == true){
		if (client && !client->getClientNickname().empty()){
			if (data.size() > 1){
				if (client->getClientUsername().empty()){
					client->setClientUsername(data[1]);
					if (client)
						clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
					if (isNicknameAvailable(client) == true){
						std::string message = RPL_WELCOME(client->getClientNickname(), clientStr);
						if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
							std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
					}
				}
				else{
//					std::cout << BOLD_RED << "username has already been get" << NORMAL << std::endl; //to comment
					std::string message = ERR_ALREADYREGISTRED(clientStr);
					if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
						std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
				}
			}
			else{
//				std::cout << BOLD_RED << "argument for username is missing" << NORMAL << std::endl; //to comment
				std::string message = ERR_NEEDMOREPARAMS(clientStr, "USER");
				if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
					std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
			}
		}
	}
	return (0);
}
