
#include "ReceivedData.hpp"

int	ReceivedData::unknownHandle(std::vector<std::string> const & data, Server *server, Client *client){

	(void)server;
	std::string clientStr;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

//	dataDisplaying(data); //to comment

	if (verifyClientCompleteIdentification(client) == true){
//		std::cout << BOLD_RED << "This command is unknown" << NORMAL << std::endl; //to comment
		if (data[0] == "WHO")
			return (0);
		std::string message = ERR_UNKNOWNCOMMAND(clientStr, data[0]);
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	}
	return (0);
	
}
