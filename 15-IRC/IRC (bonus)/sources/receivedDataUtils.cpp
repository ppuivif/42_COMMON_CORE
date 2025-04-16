
#include "ReceivedData.hpp"

/*void	ReceivedData::dataDisplaying(std::vector<std::string> const & data){
	
	for(size_t i = 0; i < data.size(); i++){
		
		if (i == 0)
			std::cout << "Command is : " << data[0] << std::endl;
		else
			std::cout << "Argument number " << i << " is : " << data[i] << std::endl;
	}
}*/

bool	ReceivedData::verifyClientCorrectPassword(Client *client){

	if (client && client->getClientCorrectPassword() == true){
		return (true);
	}
//	std::cout << BOLD_RED << "any correct password has be given previously" << NORMAL << std::endl; //to comment
	return (false);
}

bool	ReceivedData::verifyClientCorrectNickname(Client *client){

	if (client && client->getClientIsAvailableNickname() == true){
		return (true);
	}
//	std::cout << BOLD_RED << "any nickname has been given previously" << NORMAL << std::endl; //to comment
	return (false);
}

bool	ReceivedData::verifyClientCorrectUsername(Client *client){

	if (client && !client->getClientUsername().empty()){
		return (true);
	}
//	std::cout << BOLD_RED << "any username has been given previously" << NORMAL << std::endl; //to comment
	return (false);
}

bool	ReceivedData::verifyClientCompleteIdentification(Client *client){
	
	if (verifyClientCorrectPassword(client) && \
	verifyClientCorrectNickname(client) && \
	verifyClientCorrectUsername(client))
		return (true);
	return (false);
}
