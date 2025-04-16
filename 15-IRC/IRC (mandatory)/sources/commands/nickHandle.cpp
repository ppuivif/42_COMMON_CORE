
#include "ReceivedData.hpp"

static bool	isSpecialChar(char c){

	if ((c >=91 && c <= 96) || (c >= 123 && c <= 125))
		return (true);
	return (false);
}

static int	isValidNickname(std::string str){

	size_t	len = 9;
	
	if (str.size() <= 9)
		len = str.size();

	if (isSpecialChar(str[0]) == false && isalpha(str[0]) == false)
		return (-1);
	
	for(size_t i = 1; i < len ; i++){
		if (isSpecialChar(str[i]) == false && isalpha(str[i]) == false && isdigit(str[i]) == false)
			return (-1);
	}
	return (len);
}

static void	checkIfNicknameValid(std::string const & nickname, Client *client){

	std::string clientStr;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

	int len = isValidNickname(nickname);

	if (len != -1){
		client->setClientNickname(nickname.substr(0, len));
	}
	else{
//		std::cout << BOLD_RED << "nickname is not correct" << NORMAL << std::endl; //to comment
		std::string message = ERR_ERRONEUSNICKNAME(clientStr, nickname);
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	}
}

static void	checkIfNicknameAlreadyUsed(std::string const & nickname, std::vector<Client*> clientsList, Client *client){
	
	std::vector<Client*>::iterator it;
	
	for (it = clientsList.begin(); it != clientsList.end(); it++){
		if (((*it)->getClientNickname() == nickname && (*it)->getClientSocketFd() != client->getClientSocketFd())){
			client->setClientIsAvailableNickname(false);
			return ;
		}
	}
	client->setClientIsAvailableNickname(true);
}

int	ReceivedData::nickHandle(std::vector<std::string> const & data, Server *server, Client *client){
	
	std::string clientStr;
	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

//	dataDisplaying(data); //to comment
	
	if (client && verifyClientCorrectPassword(client) == true){
		if (data.size() > 1){
			checkIfNicknameAlreadyUsed(data[1], server->getClientsList(), client);
			checkIfNicknameValid(data[1], client);
		}
		else{
//			std::cout << BOLD_RED << "argument for nickname is missing" << NORMAL << std::endl; //to comment
			std::string message = ERR_NONICKNAMEGIVEN(clientStr, "*");
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
	}

	if (client)
		clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
	if (client && !client->getClientUsername().empty()){
		if (client->getClientIsAvailableNickname() == true){
			std::string message = RPL_WELCOME(client->getClientNickname(), clientStr);
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
		else{
//			std::cout << BOLD_RED << "nickname has already been used" << NORMAL << std::endl; //to comment
			std::string message = ERR_NICKNAMEINUSE(clientStr, client->getClientNickname());
			if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
	}
	return (0);
}
