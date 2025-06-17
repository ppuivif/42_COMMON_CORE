#include "BitcoinExchange.hpp"

/*void printFileContent(std::ifstream & file){

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
}*/

/*void printMapContent(std::map<std::time_t, float> map){
	std::map<std::time_t, float>::iterator it = map.begin();
	for(; it != map.end(); it++){
		std::cout << it->first << " : " << std::setprecision(7) << it->second << std::endl;
	}
}*/

static int checkYear(std::string const & line){
	
	char * pEnd;
	errno = 0;

	if (line.size() > 5){
		std::string yearString = line.substr(0, 4);
		long int yearInt = strtol(yearString.c_str(), &pEnd, 10);
		if (yearInt < 0 || (yearInt == 0 && yearString != "0000"))
			return (-1);
		if (errno == ERANGE || *pEnd != 0)
			return (-1);
		else
			return (yearInt);
	}
	return (-1);
}

static int checkMonth(std::string const & line){
	
	char * pEnd;
	if (line.size() > 5){
		std::string monthString = line.substr(5, 2);
		long int monthInt = strtol(monthString.c_str(), &pEnd, 10);
		if (monthInt <= 0 || monthInt > 12 || errno == ERANGE || *pEnd != 0)
			return (-1);
		else
			return (monthInt);
	}
	return (-1);
}

static bool isLeapYear(long int year){
	
	if (year % 4 == 0){
		if (year % 100 == 0 && year % 400)
			return (true);
	}
	return (false);
}

static int checkDay(std::string const & line, long int year, long int month){
	
	char * pEnd;
	errno = 0;

	if (line.size() > 8){
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
	return (-1);
}

static time_t	finalDateBuild(long int year, long int month, long int day){
	
	time_t finalDate;
	struct tm date = {};
	date.tm_hour = 0; date.tm_min = 0; date.tm_sec = 0;
	date.tm_year = year - 1900; date.tm_mon = month -1; date.tm_mday = day;
	finalDate = mktime(&date);
	return (finalDate);
}

static bool isValidDate(time_t finalDate){
	
	time_t timer;
	time(&timer);  // get current time

	if (finalDate == -1 || finalDate > timer)
		return (false);
	return (true);
}

long int	parsingDate(std::string const & line){
	
	long int year = checkYear(line);
	long int month = checkMonth(line);
	if (year == -1 || line[4] != '-' || month == -1 ||	line[7] != '-')
		return (-1);
	long int day = checkDay(line, year, month);
	if (day == -1)
		return (-1);
	time_t finalDate = finalDateBuild(year, month, day);
	if (isValidDate(finalDate) == false)
		return (-1);
	return (finalDate);
}

static std::string skipSpaces(std::string str){

	unsigned int i = 0;

	while (i < str.size() && str[i] == ' ')
		i++;
	return (str.substr(i));	
}

float	parsingValue(std::string const & line, std::string fileType, int separatorPos){
	
	std::string bitcoinExchangeRateString;
	std::string bitcoinInputValueString;
	char * pEnd;
	errno = 0;

	if (fileType == "CSV" && line.size() > (unsigned int)separatorPos){
		bitcoinExchangeRateString = line.substr(separatorPos + 1);
		if (bitcoinExchangeRateString.empty()){
			std::cerr << "Error : value is missing in CSV file => " << line << std::endl;
			return (-1);
		}
		float bitcoinExchangeRateFloat = strtof(bitcoinExchangeRateString.c_str(), &pEnd);
		if (errno == ERANGE || *pEnd != 0){
			std::cerr << "Error : bad input or conversion failed in CSV file => " << line << std::endl;
			return (-1);
		}
		if (bitcoinExchangeRateFloat == 0.0f && skipSpaces(bitcoinExchangeRateString) != "0" && skipSpaces(bitcoinExchangeRateString) != "0.0"){
			std::cerr << "Error : invalid conversion in CSV file => " << line << std::endl;
			return (-1);
		}
		if (bitcoinExchangeRateFloat < 0 || isinff(bitcoinExchangeRateFloat) == true){
			std::cerr << "Error : value is out of range in CSV file => " << line << std::endl;
			return (-1);
		}
		return (bitcoinExchangeRateFloat);
	}
	if (fileType == "TXT"){
		bitcoinInputValueString = line.substr(separatorPos + 1);
		if (bitcoinInputValueString.empty()){
			std::cerr << "Error : value is missing => " << line << std::endl;
			return (-1);
		}
		float bitcoinInputValueFloat = strtof(bitcoinInputValueString.c_str(), &pEnd);
		if (errno == ERANGE || *pEnd != 0){
			std::cerr << "Error : bad input or conversion failed => " << line << std::endl;
			return (-1);
		}
		if (bitcoinInputValueFloat == 0.0f && skipSpaces(bitcoinInputValueString) != "0" && skipSpaces(bitcoinInputValueString) != "0.0"){
			std::cerr << "Error : invalid conversion => " << line << std::endl;
			return (-1);
		}
		if (bitcoinInputValueFloat < 0){
			std::cerr << "Error : not a positive number => " << line << std::endl;
			return (-1);
		}
		if (bitcoinInputValueFloat > 1000){
			std::cerr << "Error : too large a number => " << line << std::endl;
			return (-1);
		}
		return (bitcoinInputValueFloat);
	}
	return (-1);
}

int	searchSeparator(std::string const & line, std::string fileType){

	std::string separator;

	if (fileType == "CSV")
		separator = ",";
	if (fileType == "TXT")
		separator = "|";

	int separatorPos = line.find(separator);
	if (separatorPos == (int)std::string::npos){
		if (fileType == "TXT")
			std::cerr << "Error : bad input (separator '"<< separator << "' is missing) => " << line << std::endl;
		return (-1);
	}
	return (separatorPos);
}