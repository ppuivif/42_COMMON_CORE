#include "Channel.hpp"
#include "Server.hpp"

Channel::Channel(const std::string name) : _channelName(name), _password(""), _limits(-1), _mode_T(true), _inviteOnly(false), _NbUserOnChannel(0) {}

Channel::~Channel() {}

std::string Channel::getChanName() const {
	return (this->_channelName);
}

std::string Channel::getUserList(){
	std::string userList;
    for (std::map<Client *, bool>::const_iterator it = _UserInfo.begin(); it != _UserInfo.end(); ++it) {
        if (!userList.empty()) 
            userList += " ";
		if (it->second == true)
			userList+= "@";
        userList += it->first->getClientNickname();
    }
    return userList;
}

std::string	Channel::getTopic() const{
	return (this->_topic);
}

int Channel::getNbUserOnChannel() const{
	return (this->_NbUserOnChannel);
}

void Channel::setNbUserOnChannel(int nb){
	this->_NbUserOnChannel = nb;
}

void Channel::setTopic(std::string newTopic){
	this->_topic = newTopic;
}

void Channel::setChanName(std::string newName) {
	this->_channelName = newName;
}

void Channel::setLimits(int limits){
	this->_limits = limits;
}

void Channel::setInviteMode(bool inviteMode){
	this->_inviteOnly = inviteMode;
}

void Channel::setPassword(std::string data){
	this->_password = data;
}

void Channel::setOperatorClient(std::string clientName, bool clientOperator){
	for(std::map<Client *, bool>::iterator it = this->_UserInfo.begin(); it != this->_UserInfo.end(); it++){
		if (it->first->getClientNickname() == clientName){
			it->second = clientOperator;
		}
	}
}

void Channel::setMode_T(bool mode_T){
	this->_mode_T = mode_T;
}

bool Channel::getMode_T() const{
	return (this->_mode_T);
}

bool Channel::getInviteOnly() {
	return (this->_inviteOnly);
}

int Channel::getLimits() const{
	return (this->_limits);
}

bool Channel::isAnOperator(Client *client){
	std::map<Client *, bool>::iterator it = _UserInfo.find(client);
	if (it != this->_UserInfo.end())
		return (it->second);
	return (false);
}

int Channel::isInChannel(Client *client){
	
	std::map<Client *, bool>::iterator it = this->_UserInfo.find(client);
	if (it != this->_UserInfo.end())
		return (0);
	return (1);
}

Client *Channel::getClientByName(const std::string &ClientName){
	
	if (this->_UserInfo.empty()){
		return NULL;
	}
	for(std::map<Client *, bool>::iterator it = this->_UserInfo.begin(); it != this->_UserInfo.end(); it++){
		if (it->first->getClientNickname() == ClientName)
			return (it->first);
	}
	return (NULL);
}

std::map<Client *, bool> const & Channel::getClientsMap() const{
	return (this->_UserInfo);
}

std::string	Channel::getPassword() const{
	return (this->_password);
}

std::vector<std::string>& Channel::getClientInvitList(){
	return (this->_ClientInvitList);
}

bool Channel::operator==(const Channel& other) const{
	return this->_channelName == other._channelName;
}

void	Channel::sendMessageToAllClients(const std::string &message){

	for(std::map<Client *, bool>::iterator it = this->_UserInfo.begin(); it != this->_UserInfo.end(); it++){
		Client *client = it->first;
		if (!client)
			return ;
		int clientFd = client->getClientSocketFd();
		if (send(clientFd, message.c_str(), message.length(), O_NONBLOCK) == -1)
			std::cerr << BOLD_RED << "Error : message failed to be sent to the client" << NORMAL << std::endl;
	}
}

void Channel::removeUser(Client *client, Server *server){
	if (this->_UserInfo.find(client) != this->_UserInfo.end()){
		this->_UserInfo.erase(client);
		this->_NbUserOnChannel += -1;
	}
	if (this->_UserInfo.empty()){
		server->clearChannel(this);
	}
}