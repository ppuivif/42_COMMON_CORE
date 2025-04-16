
#ifndef RECEIVEDDATA_HPP
# define RECEIVEDDATA_HPP

#include <iostream>
#include <vector>
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

class	Server;
class	Client;
class	Channel;

class	ReceivedData{

	public:
		ReceivedData();
		~ReceivedData();
		
		void		parseData(std::string commandLine);
		void		executeCommand(Server *server, Client *client);
		static int	passHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	nickHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	userHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	privmsgHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	joinHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	topicHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	inviteHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	kickHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	quiteHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	modeHandle(std::vector<std::string> const & data, Server *server, Client *client);
		static int	partHandle(std::vector<std::string> const & data, Server *server, Client *client);
		
		static int	unknownHandle(std::vector<std::string> const & data, Server *server, Client *client);
		
//		static void	dataDisplaying(std::vector<std::string> const & data); //to comment

		static bool	verifyClientCorrectPassword(Client *client);
		static bool	verifyClientCorrectNickname(Client *client);
		static bool	verifyClientCorrectUsername(Client *client);
		static bool	verifyClientCompleteIdentification(Client *client);
		
	private:
		std::vector<std::string>	_data;
		std::string					_command;
		std::string					_argument;
};

#endif