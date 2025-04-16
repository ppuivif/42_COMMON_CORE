#include "Channel.hpp"
#include "Client.hpp"
#include "ReceivedData.hpp"

int	ReceivedData::kickHandle(std::vector<std::string> const & data, Server *server, Client *client){

	if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == 1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }

	if (data.size() <= 2){
		std::string message = ERR_NEEDMOREPARAMS(client->getClientNickname(), "KICK");
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}
	std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
	std::string channelName = data[1];
	std::string targetName = data[2];
	Channel *targetChannel = server->getChannelByName(channelName);

	if (!targetChannel){
		std::string message = ERR_NOSUCHCHANNEL(clientStr, channelName);
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}
	if (targetChannel->isInChannel(client)){
		std::string message = ERR_NOTONCHANNEL(channelName, client->getClientNickname());
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}
	if (!targetChannel->isAnOperator(client)){
		std::string message = ERR_CHANOPRIVSNEEDED(client->getClientNickname(), targetChannel->getChanName());
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}

	Client *targetClient = server->findClientWithName(targetName);
	
	if (!targetClient){
		std::string message = ERR_NOSUCHNICK(clientStr, targetName);
		send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
		return (1);
	}
	if (targetChannel->isInChannel(targetClient)){
		std::string message = ERR_USERNOTINCHANNEL(clientStr, targetName, channelName);
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}

	targetChannel->removeUser(targetClient, server);
	
	std::string reason = (data.size() == 4) ? data[3] : targetClient->getClientNickname();
	std::string message = RPL_KICK(client->getClientNickname(), targetChannel->getChanName(), targetClient->getClientNickname(), reason);
	targetChannel->sendMessageToAllClients(message);
	if (send(targetClient->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
		std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	return (0);
}