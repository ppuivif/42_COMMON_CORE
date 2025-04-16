
#include "ReceivedData.hpp"

int	isClientInChannel(Client *client, Channel *channel, std::map<Client*, bool> clientsMap){
	
	std::map<Client *, bool>::iterator it2;
	std::string clientStr;

	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

	for(it2 = clientsMap.begin(); it2 != clientsMap.end(); it2++){
		if (channel->isInChannel(client) == 0){
			return (0);
		}
	}
//	std::cout << BOLD_RED << "client does not belong to the channel" << NORMAL << std::endl; //to comment
	std::string message = ERR_CANNOTSENDTOCHAN(clientStr, channel->getChanName());
	if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
		std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	return (1);
}

int	isChannelExists(std::vector<Channel *> channelsList, std::string const & target, Client *client, std::vector<int> & clientsSocketFdList){

	std::vector<Channel *>::iterator it1;
	std::map<Client *, bool>::iterator it2;
	
	for(it1 = channelsList.begin(); it1 != channelsList.end(); it1++){
		if (((*it1)->getChanName() == target)){

			std::map<Client*, bool> clientsMap = (*it1)->getClientsMap();
			
			if (isClientInChannel(client, *it1, clientsMap) == 1)
				return (1);

			for (it2 = clientsMap.begin(); it2 != clientsMap.end(); it2++){
				if (it2->first->getClientSocketFd() != client->getClientSocketFd())
					clientsSocketFdList.push_back(it2->first->getClientSocketFd());
			}
			return (0);
		}
	}
	std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
//	std::cout << BOLD_RED << "channel " << &target[1] << " does not exist" << NORMAL << std::endl; //to comment
	std::string message = ERR_NOSUCHCHANNEL(clientStr, target);
	if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
		std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	return (1);
}

int	isNicknameExists(std::vector<Client *> clientsList, std::string const & target, Client *client, std::vector<int> & clientsSocketFdList){

	std::vector<Client *>::iterator it;
	std::string clientStr;
	
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

	for(it = clientsList.begin(); it != clientsList.end(); it++){
		if (((*it)->getClientNickname() == target)){
			clientsSocketFdList.push_back((*it)->getClientSocketFd());
			return (0);
		}
	}
//	std::cout << BOLD_RED << "nickname " << target << " does not exist" << NORMAL << std::endl; //to comment
	std::string message = ERR_NOSUCHNICK(clientStr, target);
	if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
		std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	return (1);
}

int	getClientsSocketFdList(Server *server, std::string const & target, Client *client, std::vector<int> & clientsSocketFdList){

	if (target[0] == '#')
		return (isChannelExists(server->getChannelsList(), target, client, clientsSocketFdList));
	else
		return (isNicknameExists(server->getClientsList(), target, client, clientsSocketFdList));
}

void	botHandle(std::vector<std::string> const & data, Client *client, std::vector<int> clientsSocketFdList){

	std::string clientStr;
	std::vector<int>::iterator it;

	std::string botClientStr = CLIENT("bot", "bot");
	std::string response = "et grosminet";

	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

	std::string message = PRIVMSG(clientStr, data[1], data[2]);
	std::string messageToResponse = PRIVMSG(botClientStr, data[1], response);
		
	for (it = clientsSocketFdList.begin(); it != clientsSocketFdList.end(); it++){
		if (send(*it, message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;		
		}		
		if (data[1] == client->getClientNickname() && clientsSocketFdList.size() > 1){
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
		if (send(client->getClientSocketFd(), messageToResponse.c_str(), messageToResponse.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
}

int	ReceivedData::privmsgHandle(std::vector<std::string> const & data, Server *server, Client *client){

	std::string clientStr;
	std::vector<int> clientsSocketFdList;
	std::vector<int>::iterator it;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

//	dataDisplaying(data); //to comment

	if (verifyClientCompleteIdentification(client) == true){
		if (data.size() == 1){
//			std::cout << BOLD_RED << "argument message is missing" << NORMAL << std::endl; //to comment
			std::string message = ERR_NORECIPIENT(clientStr, "PRIVMSG");
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error :irst->get message failed to be sent to the client" << NORMAL << std::endl;
		}
		else if (data.size() == 2){
//			std::cout << BOLD_RED << "argument message is missing" << NORMAL << std::endl; //to comment
			std::string message = ERR_NOTEXTTOSEND(clientStr);
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
		else if (data.size() > 2){
			int returnValue = getClientsSocketFdList(server, data[1], client, clientsSocketFdList);
			if (!returnValue){
				if (data[2] == "titi")
					botHandle(data, client, clientsSocketFdList);
				else{
					std::string message = PRIVMSG(clientStr, data[1], data[2]);
					if (clientsSocketFdList.size()){
						for (it = clientsSocketFdList.begin(); it != clientsSocketFdList.end(); it++){
							if (send(*it, message.c_str(), message.length(), O_NONBLOCK) == -1)
								std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
						}
					}
				} 
			}
		}
	}
	else{
		std::string message = ERR_NOTREGISTERED();
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}
	return (0);
}
