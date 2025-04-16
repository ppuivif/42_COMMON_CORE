
#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>

#include "Server.hpp"
#include "Client.hpp"
#include <map>

class Server;
class Client;

class Channel{
	private:
		std::string		_channelName;
		std::map<Client *, bool> _UserInfo;
		std::vector<std::string> _ClientInvitList;
		std::string		_password;  // set a password at the channel
		std::string 	_topic;
		int	_limits; // set a limit number of user to the channel
		bool _mode_T; // set the restriction for topic command for no operator user (true : only operator) (false : all user)
		bool _inviteOnly; // set the channel on invite mode only
		int _NbUserOnChannel; //stack the number of user on the channel
	
	public:
		~Channel();
		Channel(const std::string name);
		bool operator==(const Channel& other) const;
		
		void								sendMessageToAllClients(const std::string &message);
		int 								isInChannel(Client *client);
		bool 								isAnOperator(Client *client);
		std::vector<std::string>&			getClientInvitList();
		std::string 						getChanName() const;
		Client 								*getClientByName(const std::string &clientName);
		std::string 						getUserList();
		bool 								getInviteOnly();
		std::map<Client *, bool> const &	getClientsMap() const;
		std::string 						getPassword() const;
		int									getLimits() const;
		bool								getMode_T() const;
		std::string							getTopic() const;
		int                                 getNbUserOnChannel() const;
		void								setTopic(std::string newTopic);
		void								setMode_T(bool mode_T);
		void 								setLimits(int limits);
		void 								setChanName(std::string newName);
		void 								setInviteMode(bool inviteMode);
		void 								setPassword(std::string data);
		void								setOperatorClient(std::string clientName, bool clientOperator);
		void								setNbUserOnChannel(int nb);
		void 								addUser(Client *client, bool isOperator, Channel *channel);
		void 								removeUser(Client *client, Server *server);
};

#endif