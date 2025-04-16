
#include "ReceivedData.hpp"

ReceivedData::ReceivedData(){

}

ReceivedData::~ReceivedData(){
	
}

size_t getLenToSpace(std::string remainingString){

	size_t pos = remainingString.find(' ');
	if (pos != std::string::npos)
		return (pos);
	return (remainingString.size());
}

void	convertStringToUpper(std::string & str){
	
	for(size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
}

void	ReceivedData::parseData(std::string commandLine){

	size_t	index = 0;
	size_t	startIndex = 0;
	size_t	len = 0;
	
	while(index < commandLine.size()){
		startIndex = index;
		if (commandLine[index] == ':'){
			index++;
			startIndex++;
			std::string tmp = &commandLine[index];
			len = tmp.size();
		}
		else
			len = getLenToSpace(&commandLine[index]);
		std::string stringToPush = commandLine.substr(startIndex, len);
		if (this->_data.size() == 0)
			convertStringToUpper(stringToPush);
		this->_data.push_back(stringToPush);
		index += len;
		while(commandLine[index] == ' ')
			index++;
	}
}

void	ReceivedData::executeCommand(Server * server, Client *client){

	int			index = 0;
	std::string	commands[] = {"PASS", "NICK", "USER", "PRIVMSG", "JOIN", "TOPIC", "INVITE", "KICK", "QUIT", "MODE", "PART"};

	int	(* function[12])(std::vector<std::string> const & data, Server * server, Client *client);
	function[0] = &passHandle;
	function[1] = &nickHandle;
	function[2] = &userHandle;
	function[3] = &privmsgHandle;
	function[4] = &joinHandle;
	function[5] = &topicHandle;
	function[6] = &inviteHandle;
	function[7] = &kickHandle;
	function[8] = &quiteHandle;
	function[9] = &modeHandle;
	function[10] = &partHandle;
	function[11] = &unknownHandle;
	
	for (; index < 11; index++){
		if (this->_data[0] == commands[index])
			break;
	}

//	dataDisplaying(this->_data); //to comment

	if (function[index]){
		function[index](this->_data, server, client);
	}
}
