#include "Server.hpp"
#include "ReceivedData.hpp" 
#include <sstream>

std::string toString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

std::string setMessgaeForMode(Channel *channel){
    std::string messageForMode = "+";
    if (channel->getInviteOnly())        messageForMode += "i";
    if (channel->getMode_T())            messageForMode += "t";
    if (!channel->getPassword().empty()) messageForMode += "k";
    if (channel->getLimits() != -1)      messageForMode += "l";

    return (messageForMode);

}

void    setChannelOnInviteOnly(std::string clienStr, Channel *channel, char signOfMode){
    if (signOfMode == '+' && channel->getInviteOnly() == false){
        channel->setInviteMode(true);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " " + signOfMode + "i\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
    else if (signOfMode == '-' && channel->getInviteOnly() == true){
        channel->setInviteMode(false);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " " + signOfMode + "i\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
}

void    setChannelPassword(std::string clienStr, Channel *channel, char signOfMode, std::string data){
    if (signOfMode == '+' && !data.empty()){
        channel->setPassword(data);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " +k " + data + "\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
    if (signOfMode == '-' && !channel->getPassword().empty()){
        channel->setPassword("");
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " -k\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
}

void    setChannelOperator(Server *server,std::string clienStr, Channel *channel, char signOfMode, std::string data, Client *client){
    if (data.empty())
        return;
    Client *clientOfChan = server->findClientWithName(data);
    if (!clientOfChan){
        std::string modeMessage = ERR_NOSUCHNICK(clienStr, data);
        send(client->getClientSocketFd(), modeMessage.c_str(), modeMessage.length(), O_NONBLOCK);
    }
    else if (channel->isInChannel(clientOfChan)){
        std::string modeMessage = ERR_USERNOTINCHANNEL(clienStr, data, channel->getChanName());
        send(client->getClientSocketFd(), modeMessage.c_str(), modeMessage.length(), O_NONBLOCK);
    }
    else if (signOfMode == '+'){
        channel->setOperatorClient(data, true);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " "  + signOfMode + "o" + " " + data + "\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
    else if (signOfMode == '-'){
        channel->setOperatorClient(data, false);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " " + signOfMode + "o" + " " + data + "\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
}

void    setChannelLimit(std::string clienStr, Channel *channel, char signOfMode, std::string data){
    if (signOfMode == '+'){
        int limits = std::atoi(data.c_str());
        if (limits <= 0)
            return ;
        channel->setLimits(limits);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " +l " + toString(channel->getLimits()) + "\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
    if (signOfMode == '-' && channel->getLimits() != -1){
        channel->setLimits(-1);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " -l" + "\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
}

void    setTopicForOpe(std::string clienStr, Channel *channel, char signOfMode){
    if (signOfMode == '+' && channel->getMode_T() == false){
        channel->setMode_T(true);
        std::string modeMessage = ":" + clienStr + " MODE " + channel->getChanName() + " " + signOfMode + "t\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
    if (signOfMode == '-' && channel->getMode_T() == true){
        channel->setMode_T(false);
        std::string modeMessage = ":" +clienStr + " MODE " + channel->getChanName() + " " + signOfMode + "t\r\n";
        channel->sendMessageToAllClients(modeMessage);
    }
}

int ReceivedData::modeHandle(std::vector<std::string> const & data, Server *server, Client *client){
    
    (void)server;
    if (!verifyClientCompleteIdentification(client)){
        std::string message = ERR_NOTREGISTERED();
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    std::string clientStr = CLIENT(client->getClientNickname(), client->getClientUsername());
    if (data.size() == 1) {
        std::string message = ERR_NEEDMOREPARAMS(clientStr, "MODE");
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
    if (data.size() == 2){
        std::string modeOfChannel = setMessgaeForMode(newChannel);
        std::string message = RPL_CHANNELMODEIS(clientStr, channelName, modeOfChannel);
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (0);
    }

    std::string signAndMode = data[2];
    std::string DataPassOrOpe;

    if (data.size() == 4)
        DataPassOrOpe = data[3];
    if (!newChannel->isAnOperator(client)){
        std::string message = ERR_CHANOPRIVSNEEDED(clientStr, channelName);
        if (send(client->getClientSocketFd(), message.c_str(), message.length(), O_NONBLOCK) == -1)
            std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
        return (1);
    }
    if (signAndMode[1] == 'i')
        setChannelOnInviteOnly(clientStr, newChannel, signAndMode[0]);
    else if (signAndMode[1] == 'k')
        setChannelPassword(clientStr, newChannel, signAndMode[0], DataPassOrOpe);
    else if (signAndMode[1] == 'o')
        setChannelOperator(server, clientStr, newChannel, signAndMode[0], DataPassOrOpe, client);
    else if (signAndMode[1] == 'l')
        setChannelLimit(clientStr, newChannel, signAndMode[0], DataPassOrOpe);
    else if (signAndMode[1] == 't')
        setTopicForOpe(clientStr, newChannel, signAndMode[0]);

    return (0);
}

