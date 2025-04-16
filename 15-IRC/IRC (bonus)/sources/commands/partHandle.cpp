#include "Server.hpp"
#include "ReceivedData.hpp"

int ReceivedData::partHandle(std::vector<std::string> const & data, Server *server, Client *client){
    
    if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
    if (data.size() < 2){
        std::string message = ERR_NEEDMOREPARAMS(clientStr, "PART");
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }

    Channel *newChannel = server->getChannelByName(data[1]);
    
    if (!newChannel){
        std::string message = ERR_NOSUCHCHANNEL(clientStr, data[1]);
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    if (newChannel->isInChannel(client) == 1){
        std::string message = ERR_NOTONCHANNEL(clientStr, newChannel->getChanName());
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    if (data.size() <= 2){
        std::string message = RPL_PART(clientStr, newChannel->getChanName());
        newChannel->sendMessageToAllClients(message);
    }
    else{
        std::string leaveMessage = data[2];
        std::string message = RPL_PARTMESSAGE(clientStr, newChannel->getChanName(), leaveMessage);
        newChannel->sendMessageToAllClients(message);
    }
    newChannel->removeUser(client, server);
    return (0);
}