#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs){
	*this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){
	if (this != &rhs)
		this->_exchangeRateMap = rhs._exchangeRateMap;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
}

int	BitcoinExchange::argumentsParsing(int argc, char **argv){

	if (argc != 2){
		std::cerr << BOLD_RED << "wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	if (argv[1][0] == 0){
		std::cerr << BOLD_RED << "filename is empty" << NORMAL << std:: endl;
		return (1);
	}	
	return (0);
}

float BitcoinExchange::findExchangeRate(time_t finalDate){

	std::map<time_t, float>::iterator it = this->_exchangeRateMap.begin();
	float value = 0;
	for (; it != this->_exchangeRateMap.end(); it++){
		if (it->first > finalDate)
			return (value);
		value = it->second;
	}
	return (value);
}

void	BitcoinExchange::closeStreams(void){
	this->_infileContent.close();
	this->_dataCSVContent.close();
}

void	BitcoinExchange::parsingData(std::string const & line, std::string fileType){
	int separatorPos = searchSeparator(line, fileType);
	if (separatorPos == -1)
		return;
	
	time_t finalDate = parsingDate(line);
	if (finalDate == -1){
		std::cout << "Error : bad input => " << line << std::endl;
		return ;
	}

	float value = parsingValue(line, fileType, separatorPos);
	if (fileType == "CSV" && finalDate != -1 && value != -1){
		std::map<time_t, float>::iterator it = this->_exchangeRateMap.find(finalDate);
		if (it != this->_exchangeRateMap.end())
			std::cout << BOLD_RED << "There are at least 2 values for the same date in the CSV file" << NORMAL << std::endl;
		else
			this->_exchangeRateMap.insert(std::pair<time_t, float>(finalDate, value));
	}
	if (fileType == "TXT" && finalDate != -1 && value != -1){
		float exchangeRate = this->findExchangeRate(finalDate);
		float result = value * exchangeRate;
		std::cout << line.substr(0, 10) << " => " << std::setprecision(7) << value << " = " << result << std::endl;
	}
}

int BitcoinExchange::loadDataCSVContent(){
	
	this->_dataCSVContent.open("./data.csv", std::ifstream::in);
	if (!this->_dataCSVContent.is_open())
	{
		std::cerr << BOLD_RED << "data.csv couldn't be opened or do not exist" << NORMAL << std:: endl;
		return (1);
	}

	std::string		line;
	std::getline(this->_dataCSVContent, line);
	while (std::getline(this->_dataCSVContent, line)){
		if (!line.empty())
			parsingData(line, "CSV");
	}
//	printFileContent(this->getDataCSVContent());
//	printMapContent(this->_exchangeRateMap);
	this->closeStreams();
	return (0);
}

int BitcoinExchange::loadInfileContent(std::string infile){
	
	this->_infileContent.open(infile.c_str(), std::ifstream::in);
	if (!this->_infileContent.is_open())
	{
		std::cerr << BOLD_RED << "infile couldn't be opened or do not exist" << NORMAL << std:: endl;
		return (1);
	}
	
	std::string		line;
	std::getline(this->_infileContent, line);
	while (std::getline(this->_infileContent, line)){
		if (!line.empty())
			parsingData(line, "TXT");
	}
//	printMapContent(this->_inputValueMap);
	this->closeStreams();
	return (0);
}
