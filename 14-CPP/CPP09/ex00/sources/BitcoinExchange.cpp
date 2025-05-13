#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs){
	*this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){
	if (this != &rhs)
		this->_map = rhs._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
}

int	BitcoinExchange::parsing(int argc, char **argv){

	if (argc != 2)
	{
		std::cerr << BOLD_RED << "wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	if (argv[1][0] == 0)
	{
		std::cerr << BOLD_RED << "filename is empty" << NORMAL << std:: endl;
		return (1);
	}	
	return (0);
}

int BitcoinExchange::getInfileContent(std::string infile){

	this->_infileContent.open(infile.c_str(), std::ifstream::in);
	if (!this->_infileContent.is_open())
	{
		std::cerr << BOLD_RED << "infile couldn't be opened or do not exist" << NORMAL << std:: endl;
		return (1);
	}
	return (0);
}

void	BitcoinExchange::closeStreams(void){
	this->_infileContent.close();
	this->_dataCSVContent.close();
}

/*void BitcoinExchange::printFileContent(){

	std::string		line;

	while (std::getline(this->dataCSVContent, line))
	{
		std::cout << line << std::endl;
	}
}*/

void printFileContent(std::ifstream & file){

	// Save the current position
	std::streampos originalPos = file.tellg();

	// Make a copy of the stream content using a stringstream
//	std::stringstream buffer;
//	buffer << file.rdbuf(); // Copies full content from file

	std::string		line;

	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}

// Restore the stream's position (optional, if you want it to behave as untouched)
		file.clear();				// Clear any EOF flags
		file.seekg(originalPos);	// Return to original position
}

std::ifstream & BitcoinExchange::getDataCSVContent(void) {
	return (this->_dataCSVContent);
}

int checkYear(std::string const & line){

	char * pEnd;
	std::string yearString = line.substr(0, 4);
	long int yearInt = strtol(yearString.c_str(), &pEnd, 10);
	if (yearInt <= 0 || errno == ERANGE || *pEnd != 0)
		return (-1);
	else
		return (yearInt);
}

int checkMonth(std::string const & line){
	
	char * pEnd;
	std::string monthString = line.substr(5, 2);
	long int monthInt = strtol(monthString.c_str(), &pEnd, 10);
	if (monthInt <= 0 || monthInt > 12 || errno == ERANGE || *pEnd != 0)
		return (-1);
	else
		return (monthInt);
}

bool isLeapYear(long int year){
	
	if (year % 4 == 0){
		if (year % 100 == 0 && year % 400)
		return (true);
	}
	return (false);
}

int checkDay(std::string const & line, long int year, long int month){

	char * pEnd;
	std::string dayString = line.substr(8, 2);
	long int dayInt = strtol(dayString.c_str(), &pEnd, 10);
	if (dayInt <= 0 || dayInt > 31 || errno == ERANGE || *pEnd != 0)
		return (-1);
	if (isLeapYear(year) == false && month == 2 && dayInt > 28)
		return (-1);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && dayInt > 30)
		return (-1);
	else
		return (dayInt);
}

long int	parsingCSVDate(std::string line){

	long int year = checkYear(line);
//	std::cout << "year : " << year << std::endl;
	long int month = checkMonth(line);
//	std::cout << "month : " << month << std::endl;

	if (year == -1 || line[4] != '-' || month == -1 ||	line[7] != '-')
		return (-1);
	long int day = checkDay(line, year, month);
//	std::cout << "day : " << day << std::endl;
	
	if (day == -1){
		return (-1);
	}
	
	time_t timer;
	time_t finalDate;
	struct tm date = {};
	date.tm_hour = 0; date.tm_min = 0; date.tm_sec = 0;
	date.tm_year = year; date.tm_mon = month; date.tm_mday = day;
	finalDate = mktime(&date);
	
	time(&timer);  // get current time
	double seconds = difftime(timer,finalDate);
	if(seconds > 0){
		std::cout << seconds << std::endl;
		return (-1);
	}
	return (finalDate);
}

long int	parsingCSVData(std::string line){
	time_t finalDate =  parsingCSVDate(line);
	return (finalDate);
}

int BitcoinExchange::loadDataCSVContent(){
	
	this->_dataCSVContent.open("./data.csv", std::ifstream::in);
	if (!this->_dataCSVContent.is_open())
	{
		std::cerr << BOLD_RED << "data.csv couldn't be opened or do not exist" << NORMAL << std:: endl;
		return (1);
	}

	std::string		line;
	while (std::getline(this->_dataCSVContent, line)){
		if (!line.empty()){
			if (parsingCSVData(line) == -1){
				std::cout << BOLD_RED << "Date is not valid" << NORMAL << std::endl;
			}
		}
	}

/*	std::string date;
	float number;
	this->_map.insert(std::pair<std::string, float>(date, number));*/


	printFileContent(this->getDataCSVContent());
	return (0);
}

