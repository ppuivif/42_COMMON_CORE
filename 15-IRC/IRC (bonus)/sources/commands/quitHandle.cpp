#include "ReceivedData.hpp"

int ReceivedData::quiteHandle(std::vector<std::string> const & data, Server *server, Client *client){

	if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }

	(void)data;

	std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
	std::vector<Channel *> &channels = server->getChannelsList();

	for(size_t i = 0; i < channels.size(); i++) {
		Channel *channel = channels[i];
		if (!channel) {
//			std::cerr << "Error: Channel is NULL" << std::endl; //to comment
			continue;
		}
		Client *targetClient = channel->getClientByName(client->getClientNickname());
		if (!targetClient) {
			continue;
		}
		std::string message = (data.size() > 1) ? data[1] : "Leaving";
		std::string quitMsg = RPL_QUIT(clientStr, message);
		channel->sendMessageToAllClients(quitMsg);
		channel->removeUser(client, server);
	}
	int fd = client->getClientSocketFd();
	server->clearClient(fd);
	close(fd);
	server->eraseFdInPollfds(fd);
	std::cout << BOLD_RED << "Client " << fd << " is disconnected" << NORMAL << std::endl;
	return (0);
}