#include "Channel.hpp"
#include "ReceivedData.hpp"

void Channel::addUser(Client *client, bool isOperator, Channel *channel){
	if (!client){
		return ;
	}
	if (this->_UserInfo.find(client) != _UserInfo.end()){
		return ;
	}
	this->_UserInfo.insert(std::make_pair(client, isOperator));
	channel->_NbUserOnChannel += 1;
}

int checkIsInvite(Channel *newChannel, Client *client){
	for (std::vector<std::string>::iterator it = newChannel->getClientInvitList().begin(); it != newChannel->getClientInvitList().end(); it++){
		if (it->c_str() == client->getClientNickname())
			return (0);
	}
	return (1);
}

void removeInviteUser(Channel *newChannel, Client *client){
	for (std::vector<std::string>::iterator it = newChannel->getClientInvitList().begin(); it != newChannel->getClientInvitList().end(); it++){
		if (it->c_str() == client->getClientNickname())
			it->erase();
	}
}

int	ReceivedData::joinHandle(std::vector<std::string> const & data, Server *server, Client *client){
	
	(void)client;

	if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
	}

	std::string clientStr;
	std::string passwordData;
	clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
	if (data.size() < 2){
		std::string message = ERR_NEEDMOREPARAMS(clientStr, "JOIN");
		if(send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}

	Channel *newChannel = NULL;
	std::string dataChannel = data[1];
	if (data[1][0] != '#'){
		std::string message = ERR_NOSUCHCHANNEL(clientStr, data[1]);
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		return (1);
	}
	std::vector<Channel*>& channels = server->getChannelsList();
	for (size_t i = 0; i < channels.size(); i++){
		if (channels[i]->getChanName() == dataChannel){
			newChannel = channels[i];
			break;
		}
	}

	if (newChannel == NULL){
		newChannel =  new Channel(data[1]);
		server->getChannelsList().push_back(newChannel);
		newChannel->addUser(client, true, newChannel);;
		std::string message = RPL_JOIN(clientStr, newChannel->getChanName());
		if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		std::string messageName = RPL_NAMEREPLY(client->getClientNickname(), newChannel->getChanName(), newChannel->getUserList());
		if (send(client->getClientSocketFd(), messageName.c_str(), messageName.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		std::string messageEnd = RPL_ENDOFNAMES(clientStr, newChannel->getChanName());
		if (send(client->getClientSocketFd(), messageEnd.c_str(), messageEnd.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
			
	}
	else {
		if (newChannel && !newChannel->isInChannel(client))
			return (0);
		if (newChannel->getInviteOnly() == true){
			if (checkIsInvite(newChannel, client) == 1){
				std::string message = ERR_INVITEONLYCHAN(clientStr, newChannel->getChanName());
				if(send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
					std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
				return (1);
			}
		}
		if (!newChannel->getPassword().empty()){
			if (data.size() == 3)
				passwordData = data[2];
			if (passwordData.empty() || newChannel->getPassword() != data[2]){
				std::string message = ERR_BADCHANNELKEY(clientStr, newChannel->getChanName());
				if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
					std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
				return (1);
			}
		}
		if (newChannel->getLimits() == -1 || newChannel->getNbUserOnChannel() < newChannel->getLimits()){
			newChannel->addUser(client, false, newChannel);
			std::string message = RPL_JOIN(clientStr, newChannel->getChanName());
			newChannel->sendMessageToAllClients(message);
			std::string messageName = RPL_NAMEREPLY(client->getClientNickname(), newChannel->getChanName(), newChannel->getUserList());
			newChannel->sendMessageToAllClients(messageName);
			std::string messageEnd = RPL_ENDOFNAMES(clientStr, newChannel->getChanName());
			newChannel->sendMessageToAllClients(messageEnd);
			removeInviteUser(newChannel, client);
		}
		else if (newChannel->getNbUserOnChannel() >= newChannel->getLimits()){
			std::string messageIsFull = ERR_CHANNELISFULL(clientStr, newChannel->getChanName());
			if (send(client->getClientSocketFd(), messageIsFull.c_str(), messageIsFull.length(), O_NONBLOCK) == -1)
				std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
		}
	}
	return (0);
}