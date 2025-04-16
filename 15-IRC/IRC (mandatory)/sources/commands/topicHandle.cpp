#include "ReceivedData.hpp"
#include "Server.hpp"

int	ReceivedData::topicHandle(std::vector<std::string> const & data, Server *server, Client *client){

    if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
    if (data.size() == 1){
        std::string message = ERR_NEEDMOREPARAMS(clientStr, "TOPIC");
            if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
                std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
            return (1);
    }

    std::string channelName = data[1];
    Channel *newChannel = server->getChannelByName(channelName);

    if (!newChannel){
        std::string message = ERR_NOSUCHCHANNEL(clientStr, channelName);
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    if (newChannel->getMode_T() == true){
        if (data.size() == 2 && !newChannel->getTopic().empty()){
            std::string message = RPL_SEETOPIC(clientStr, channelName, newChannel->getTopic());
            if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
                std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
            return (1);
        }
        else if (newChannel->getTopic().empty() && !newChannel->isInChannel(client) && data.size() == 2){
            std::string message = RPL_NOTOPIC(clientStr, channelName);
            if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
                std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
            return (1);
        }
        else if (!newChannel->isAnOperator(client) && !newChannel->isInChannel(client)){
            std::string message = ERR_CHANOPRIVSNEEDED(clientStr, channelName);
            if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
                std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
            return (1);
        }
    }
    if (data.size() == 2 && !newChannel->getTopic().empty()){
        std::string message = RPL_SEETOPIC(clientStr, channelName, newChannel->getTopic());
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
    }
    else if (data.size() == 3 && !newChannel->isInChannel(client)){
        std::string topicData = data[2];
        newChannel->setTopic(topicData);
        std::string message = RPL_TOPIC(client->getClientNickname(), newChannel->getChanName(), newChannel->getTopic());
        newChannel->sendMessageToAllClients(message);
    }
    else if (data.size() == 3 && newChannel->isInChannel(client)){
        std::string message = ERR_NOTONCHANNEL(clientStr, newChannel->getChanName());
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    else if (newChannel->getTopic().empty() && newChannel->isInChannel(client)){
        std::string message = RPL_NOTOPIC(clientStr, newChannel->getChanName());
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
    } 
    return (0);
}
