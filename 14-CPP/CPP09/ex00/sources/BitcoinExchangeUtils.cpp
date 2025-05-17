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
	if (line.size() > 5){
		std::string yearString = line.substr(0, 4);
		long int yearInt = strtol(yearString.c_str(), &pEnd, 10);
		if (yearInt <= 0 || errno == ERANGE || *pEnd != 0)
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
	
	//	check if finaleDate == -1
	time_t timer;
	time(&timer);  // get current time
	if (finalDate > timer)
	return (false);
	return (true);
}

long int	parsingDate(std::string const & line){
	
	long int year = checkYear(line);
	long int month = checkMonth(line);
	if (year == -1 || line[4] != '-' || month == -1 ||	line[7] != '-')
		return (-1);
	long int day = checkDay(line, year, month);
	if (day == -1){
		return (-1);
	}
	time_t finalDate = finalDateBuild(year, month, day);
	if (isValidDate(finalDate) == false)
	return (-1);
	return (finalDate);
}

float	parsingValue(std::string const & line, std::string fileType, int separatorPos){
	
	char * pEnd;
	if (fileType == "CSV" && line.size() > (unsigned int)separatorPos){
		std::string bitcoinExchangeRateString = &line[separatorPos + 1];
		float bitcoinExchangeRateFloat = strtof(bitcoinExchangeRateString.c_str(), &pEnd);
		if (bitcoinExchangeRateFloat < 0 || errno == ERANGE || *pEnd != 0)
			return (-1);
		return (bitcoinExchangeRateFloat);
	}
	if (fileType == "TXT"){
		if (line.size() == (unsigned int)separatorPos + 1){
			std::cout << "Error : value is missing => " << line << std::endl;
			return (-1);
		}
		std::string bitcoinInputValueString = &line[separatorPos + 1];
		float bitcoinInputValueFloat = strtof(bitcoinInputValueString.c_str(), &pEnd);
		if (errno == ERANGE || *pEnd != 0){
			std::cout << "Error : bad input => " << bitcoinInputValueString << std::endl;
			return (-1);
		}
		if (bitcoinInputValueFloat < 0){
			std::cout << "Error : not a positive number => " << bitcoinInputValueString << std::endl;
			return (-1);
		}
		if (bitcoinInputValueFloat > 1000){
			std::cout << "Error : too large a number => " << bitcoinInputValueString << std::endl;
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
			std::cout << "Error : bad input (separator '"<< separator << "' is missing) => " << line << std::endl;
		return (-1);
	}
	return (separatorPos);
}