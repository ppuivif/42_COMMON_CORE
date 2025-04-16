
#include "Server.hpp"
#include "Client.hpp"
#include "ReceivedData.hpp"

bool Server::signal = false;

Server::Server() : _portNumber (-1){

}

Server::Server(int const portNumber, std::string const & password) : _portNumber(portNumber), _password(password){

}

Server::~Server(){
	for (size_t i = 0; i < _channelsList.size(); i++)
		delete _channelsList[i];
	_channelsList.clear();
}

void	Server::signalHandler(int signal){

	if (signal == SIGINT || signal == SIGQUIT){
		Server::signal = true;
		std::cout << BOLD_RED << "\nServer has been shut down by signal" << NORMAL << std::endl;
	}
}

std::vector<Channel*>& Server::getChannelsList(){
	return (_channelsList);
}

std::vector<Client *>& Server::getClientsList(){
	return (this->_clientsList);
}

Channel *Server::getChannelByName(const std::string &channelName){
	for(size_t i = 0; i < this->_channelsList.size(); i++){
		if (this->_channelsList[i]->getChanName() == channelName)
			return (this->_channelsList[i]);
	}
	return (NULL);
}

int	Server::getPortNumber() const{
	return (this->_portNumber);
}

std::string	const &	Server::getPassword() const{
	return (this->_password);
}

int	Server::getServerSocketFd()const{
	return (this->_serverSocketFd);
}

void	Server::setServerSocketFd(int fd){
	this->_serverSocketFd = fd;
}

int	Server::createServerSocket(){
		
	int enable1 = 1;
	int enable2 = 1;
	
	this->_serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);

	if (this->_serverSocketFd == -1){
		std::cerr << BOLD_RED << "Error : socket server creation failed" << NORMAL << std::endl;
		return (1);
	}

	if (setsockopt(this->_serverSocketFd, SOL_SOCKET, SO_REUSEADDR, &enable1, sizeof(enable1)) == -1){
		std::cerr << BOLD_RED << "Error : socket server REUSADDR setting up failed" << NORMAL << std::endl;
		return (1);
	}

	if (setsockopt(this->_serverSocketFd, SOL_SOCKET, SO_REUSEPORT, &enable2, sizeof(enable2)) == -1){
		std::cerr << BOLD_RED << "Error : socket server REUSEPORT setting up failed" << NORMAL << std::endl;
		return (1);
	}

	if (fcntl(this->_serverSocketFd, F_SETFL, O_NONBLOCK) == -1){
		std::cerr << BOLD_RED << "Error : socket server setting up in non blocking mode failed" << NORMAL << std::endl;
		return (1);
	}

	return (0);
}

void	Server::storeNewSocketInPoll(int fd){

	struct pollfd newPoll;

	newPoll.fd = fd;
	newPoll.events = POLLIN;
	newPoll.revents = 0;
	this->_pollFds.push_back(newPoll);
}

int	Server::runServerSocket(){

	struct sockaddr_in serverAddress;

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(this->_portNumber);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	if (bind(this->_serverSocketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1){
		std::cerr << BOLD_RED << "Error : socket server binding failed" << NORMAL << std::endl;
		return (1);
	}

	if (listen(this->_serverSocketFd, SOMAXCONN))
		std::cerr << BOLD_RED << "Error : socket servewinsock2.h" << NORMAL << std::endl;

	storeNewSocketInPoll(this->_serverSocketFd);
	return (0);
}

int	Server::acceptNewClient(){

	struct sockaddr_in	clientAddress;
	socklen_t			clientAddressLen = sizeof(clientAddress);
	Client				*newClient = new Client;

	newClient->setClientCorrectPassword(false);
	newClient->setClientIsAvailableNickname(false);
	
	int clientSocketFd = accept(this->_serverSocketFd, (sockaddr *) &clientAddress, &clientAddressLen);
	if (clientSocketFd == -1){
		std::cerr << BOLD_RED << "Error : socket client creation via accept() failed" << NORMAL << std::endl;
		return (1);
	}
	
	if (fcntl(clientSocketFd, F_SETFL, O_NONBLOCK) == -1){
		std::cerr << BOLD_RED << "Error : client socket setting up in non blocking mode failed" << NORMAL << std::endl;
		return (1);
	}
	
	storeNewSocketInPoll(clientSocketFd);
	newClient->setClientSocketFd(clientSocketFd);
	newClient->setClientIPAddress(inet_ntoa(clientAddress.sin_addr));
	newClient->setClientCorrectPassword(false);
	this->_clientsList.push_back(newClient);
	
	std::cout << GREEN << "New client connected with FD: " << clientSocketFd << " with ip: " << inet_ntoa(clientAddress.sin_addr) << " with Port: " << ntohs(clientAddress.sin_port) << NORMAL << std::endl;

	return (0);
}


void	Server::clearClient(int fd){
	
	std::vector<Client*>::iterator it;
	
	for (it = this->_clientsList.begin(); it != this->_clientsList.end() ; it++){
		if (fd == (*it)->getClientSocketFd()){
			delete *it;
			this->_clientsList.erase(it);
			return ;
		}
	}
	std::cerr << BOLD_RED << "Error : client fd " << fd << " has not been found and could not be erased from _clientsList vector" << NORMAL << std::endl;
}

void Server::clearChannel(Channel *channel){
	if(this->_channelsList.empty())
		return;
	std::vector<Channel *>::iterator it = this->_channelsList.begin();
	while (it != this->_channelsList.end()){
		if (*it == channel){
			delete *it;
			this->_channelsList.erase(it);
			return ;
		}
		else{
			it++;
		}
	}
}

void	Server::eraseFdInPollfds(int fd){
	
	std::vector<struct pollfd>::iterator it;

	for(it = this->_pollFds.begin(); it != this->_pollFds.end() ; it++){
		if (fd == (*it).fd){
			this->_pollFds.erase(it);
			return ;
		}
	}
	std::cerr << BOLD_RED << "Error : client fd " << fd << " has not been found and could not be erased from _pollFds vector" << NORMAL << std::endl;
}

Client * Server::findClient(int fd){
	for (std::vector<Client*>::iterator it = this->_clientsList.begin(); it != this->_clientsList.end() ; it++){
		if (fd == (*it)->getClientSocketFd())
			return *it;
	}
	std::cerr << BOLD_RED << "Error : client " << fd << " has not been found" << NORMAL << std::endl;
	return (NULL);
	
}

Client * Server::findClientWithName(std::string const &name){

	std::vector<Client*>::iterator it;

	for (it = this->_clientsList.begin(); it != this->_clientsList.end() ; it++){
		if (name == (*it)->getClientNickname())
			return *it;
	}
	return (NULL);
}

/*void	displayCommandsList(std::vector<std::string> commandsList){

	std::vector<std::string>::iterator it;
	int i = 0;
	
	for (it = commandsList.begin(); it != commandsList.end(); it++){
		std::cout << "at i " << i << " : " << *it << std::endl;
		i++;
	}
}*/

void	Server::setBufferMap(int fd, char *buffer, std::vector<std::string> &commandsList){
	
	std::pair<std::map<int, std::string>::iterator,bool> ret;
	size_t pos;

	ret = this->bufferMap.insert(std::pair<int, std::string>(fd, buffer));
	if (ret.second == false)
	ret.first->second += buffer;

	while ((pos = ret.first->second.find('\n')) != std::string::npos){
		std::string commandLine = ret.first->second.substr(0, pos); // \n skipped
		if (!commandLine.empty()){
			if (commandLine[commandLine.size() - 1] == '\r')
				commandLine.erase(commandLine.size() - 1); // \r skipped
			commandsList.push_back(commandLine);
		}
		ret.first->second.erase(0, pos + 1);
	}

//	displayCommandsList(commandsList); //to comment
}

int Server::receiveNewData(int fd){

	char									buffer[512];
	std::string								commandLine;
	Client									* client;
	std::vector<std::string>				commandsList;
	std::vector<std::string>::iterator		it;
	
	memset(buffer, 0, sizeof(buffer));
	
	ssize_t bytes = recv(fd, buffer, sizeof(buffer) - 1 , 0);

	client = findClient(fd);
	if (!client){
		close(fd);
		eraseFdInPollfds(fd);
		return (1);
	}
	if (bytes <= 0){ //	to check if client disconnect
		const std::vector<std::string> emptyVec;
		if (ReceivedData::verifyClientCompleteIdentification(client))
			ReceivedData::quiteHandle(emptyVec, this, client); //for clients in channels
		else{ //if registration in progress
			std::cout << BOLD_RED << "Client " << fd << " is disconnected" << NORMAL << std::endl;
			clearClient(fd);
			close(fd);
			eraseFdInPollfds(fd);
		}
		return (0);
	}
	else{
		buffer[bytes] = '\0';
		setBufferMap(fd, buffer, commandsList);
		if (commandsList.size()){
			for (it = commandsList.begin(); it != commandsList.end(); it++){
				ReceivedData newData;
				if ((*it).size()){
					newData.parseData(*it);
					newData.executeCommand(this, client);
				}
			}
		}
		return (0);
	}
}

void	Server::startServer(){

	while (Server::signal == false){
		if (poll(_pollFds.data(), _pollFds.size(), -1) == -1){
			if (Server::signal == false)
				std::cerr << BOLD_RED << "Error : poll failed" << NORMAL << std::endl;
			break ;
		}
		if (Server::signal == true)
			break ;

		for(size_t i = 0; i < _pollFds.size() ; i++){

			if (_pollFds[i].revents & POLLIN){
				if (_pollFds[i].fd == this->_serverSocketFd){
					if (acceptNewClient())
						break ;
				}
				else{
					if (receiveNewData(_pollFds[i].fd))
						break ;
				}
			}
		}
	}
}

void	Server::clearServer(){

	std::vector<Client*>::iterator it;
	
	for (it = this->_clientsList.begin(); it != this->_clientsList.end() ; it++)
		delete *it;
	this->closeFds();
}

void Server::closeFds(){

	std::vector<struct pollfd>::iterator it;
	
	for (it = this->_pollFds.begin(); it != this->_pollFds.end() ; it++){
		close((*it).fd);
	}
}
