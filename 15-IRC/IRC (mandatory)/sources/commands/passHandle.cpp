
#include "ReceivedData.hpp"

int	ReceivedData::passHandle(std::vector<std::string> const & data, Server * server, Client *client){

	std::string clientStr;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
	
//	dataDisplaying(data); //to comment

	if (data.size() > 1){
		if (client){
			if (client->getClientCorrectPassword() == false){
				if (data[1] == server->getPassword()){
//					std::cout << GREEN << "password is right" << NORMAL << std::endl; //to comment
					client->setClientCorrectPassword(true);
				}
				else{
//					std::cout << BOLD_RED << "password is wrong" << NORMAL << std::endl; //to comment
					std::string message = ERR_PASSWDMISMATCH(clientStr);
					if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
						std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
				}
			}
			else{
//				std::cout << BOLD_RED << "password has already been get" << NORMAL << std::endl; //to comment
				std::string message = ERR_ALREADYREGISTRED(clientStr);
				if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
					std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
			}
}
	}
	else{
//		std::cout << BOLD_RED << "argument for password is missing" << NORMAL << std::endl; //to comment
		std::string message = ERR_NEEDMOREPARAMS(clientStr, "PASS");
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	}
	return (0);
}
