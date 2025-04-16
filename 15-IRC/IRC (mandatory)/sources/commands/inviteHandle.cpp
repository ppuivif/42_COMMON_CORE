#include "ReceivedData.hpp"
#include "Channel.hpp"

int	ReceivedData::inviteHandle(std::vector<std::string> const & data, Server *server, Client *client){
	
	if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
        return (1);
    }
	std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());

	if (data.size() <= 2){
		std::string message = ERR_NEEDMOREPARAMS(clientStr, "INVITE");
		send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
		return 1;
	}
	std::string channelName = data[2];
	std::string NickOfInvite = data[1];
	Channel *newChannel = server->getChannelByName(channelName);
	Client *clientTarget = NULL;
	int InviteClientSocket = 0;

	std::vector<Client *>::iterator it = server->getClientsList().begin();

	for (; it != server->getClientsList().end(); it++){
		if ((*it)->getClientNickname() == NickOfInvite){
			InviteClientSocket = (*it)->getClientSocketFd();
		}
	}
	if (it == server->getClientsList().end() && InviteClientSocket == 0){
		std::string message = ERR_NOSUCHNICK(clientStr, NickOfInvite);
		send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
		return (1);
	}
	if (!newChannel){
		std::string message = ERR_NOSUCHCHANNEL(clientStr, channelName);
		send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
		return (1);
	}
	else {
		if (newChannel->isInChannel(client)){
			std::string message = ERR_NOTONCHANNEL(clientStr, newChannel->getChanName());
			send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
			return (1);
		}
		clientTarget = newChannel->getClientByName(NickOfInvite);
		if (clientTarget){
			std::string message = ERR_USERONCHANNEL(clientTarget->getClientNickname(), newChannel->getChanName());
			send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
			return (1);
		}
		if (!newChannel->isAnOperator(client)){
			std::string message = ERR_CHANOPRIVSNEEDED(clientStr, channelName);
			send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK);
			return (1);
		}
		newChannel->getClientInvitList().push_back(NickOfInvite);
		std::string messageToInvite = RPL_INVITERCVR(clientStr, NickOfInvite, newChannel->getChanName());
		send(InviteClientSocket, messageToInvite.c_str(), messageToInvite.length(), O_NONBLOCK);
		std::string messageToClient = RPL_INVITESNDR(clientStr, NickOfInvite, newChannel->getChanName());
		send(client->getClientSocketFd(), messageToClient.c_str(), messageToClient.length(), O_NONBLOCK);
		return 0;
	}
}