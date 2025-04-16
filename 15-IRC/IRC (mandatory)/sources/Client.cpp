
#include "Client.hpp"

Client::Client(){

	this->_clientSocketFd = -1;
	this->_clientCorrectPassword = false;
}

Client::~Client(){

}

int	Client::getClientSocketFd() const{
	return (this->_clientSocketFd);
}

std::string const &	Client::getClientNickname() const{
	return (this->_clientNickname);
}

std::string	const &	Client::getClientUsername() const{
	return (this->_clientUsername);
}

bool	Client::getClientCorrectPassword() const{
	return (this->_clientCorrectPassword);
}

bool	Client::getClientIsAvailableNickname() const{
	return (this->_clientIsAvailableNickname);
}

char	* Client::getClientIPAddress() const{
	return (this->_clientIPAddress);
}

void	Client::setClientSocketFd(int fd){
	this->_clientSocketFd = fd;
}

void	Client::setClientNickname(std::string nickname){
	this->_clientNickname = nickname;
}

void	Client::setClientUsername(std::string username){
	this->_clientUsername = username;
}

void	Client::setClientIPAddress(char * IPAddress){
	this->_clientIPAddress = IPAddress;
}

void	Client::setClientCorrectPassword(bool correctPassword){
	this->_clientCorrectPassword = correctPassword;
}

void	Client::setClientIsAvailableNickname(bool availableNickname){
	this->_clientIsAvailableNickname = availableNickname;
}