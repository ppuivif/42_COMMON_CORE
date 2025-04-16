
#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <iostream>
#include <vector> //for vector _clientsList
#include <arpa/inet.h> //for inet_ntoa

#include "Channel.hpp"

class Channel;

class Client{

	public:
		Client();
		~Client();

		int					getClientSocketFd() const;
		std::string	const & getClientNickname() const;
		std::string	const & getClientUsername() const;
		char			 	* getClientIPAddress() const;
		bool				getClientCorrectPassword() const;
		bool				getClientIsAvailableNickname() const;

		void	setClientSocketFd(int fd);
		void	setClientNickname(std::string nickname);
		void	setClientUsername(std::string username);
		void	setClientIPAddress(char * IPAddress);
		void	setClientCorrectPassword(bool correctPassword);
		void	setClientIsAvailableNickname(bool correctNickname);

	private:
		int					_clientSocketFd;
		std::string			_clientNickname;
		std::string			_clientUsername;
		char				* _clientIPAddress;
		bool				_clientCorrectPassword;
		bool				_clientIsAvailableNickname;
};

#endif