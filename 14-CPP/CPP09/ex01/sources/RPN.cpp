#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN const & rhs){
	*this = rhs;
}

RPN & RPN::operator=(RPN const & rhs){
//	if (this != &rhs)
	(void)rhs;
	return (*this);
}

static bool isOperator(char character){
	if (character == '+' || character == '-' || character == '*' || character == '/')
		return (true);
	else
		return (false);
}

static void skipSpaces(std::string & remainingString){

	while (remainingString[0] == ' '){
		remainingString = &remainingString[1];
	}
}

static std::string getNextCharacter(std::string & remainingString){
	
	skipSpaces(remainingString);
	std::string character;
	size_t pos = remainingString.find(" ");
	if (pos != std::string::npos){
		character = remainingString.substr(0, pos);
		remainingString = &remainingString[pos + 1];
	}
	else{
		character = remainingString;
		remainingString = "";
	}
	return(character);
}

int RPN::calculate(char character){
	
	if (_stack.size() < 2){
		std::cout << BOLD_RED << "Error : calculation is not possible (numbers are missing)" << NORMAL << std::endl;
		return (1);
	}
	
	int result = 0;
	int secondOperand = this->_stack.top();
	this->_stack.pop();
	int firstOperand = this->_stack.top();
	this->_stack.pop();
	
	if (character == '+')
		result = firstOperand + secondOperand;
	if (character == '-')
		result = firstOperand - secondOperand;
	if (character == '*')
		result = firstOperand * secondOperand;
	if (character == '/'){
		if (secondOperand != 0)	
			result = firstOperand / secondOperand;
		else{
			std::cout << BOLD_RED << "Error : calculation is not possible (division per zero)" << NORMAL << std::endl;
			return (1);
		}
	}
//	std::cout << result << std::endl;
	this->_stack.push(result);
	return (0);
}

int RPN::loadCharacters(char *argv){
	
	std::string remaingString = argv;
	
	while (remaingString.size()){
		std::string character = getNextCharacter(remaingString);
		if (character.size() > 1){
			std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
			return (1);
		}
		if (character.size() == 1){
			if (isdigit(character[0]))
				this->_stack.push(atoi(character.c_str()));
			else if (isOperator(character[0])){
				if (calculate(character[0]) == 1)
					return (1);
			}
			else{
				std::cout << BOLD_RED << "Error : at least one argument is invalid" << NORMAL << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int RPN::parsingArguments(int argc, char **argv){
	
	if (argc != 2){
		std::cerr << BOLD_RED << "Error : wrong number of arguments" << NORMAL << std:: endl;
		return (1);
	}
	
	if (loadCharacters(argv[1]) == 1)
		return (1);

	return (0);
}

void RPN::displayResult(){

	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else
		std::cout << BOLD_RED << "Error : calculation is not possible (too many numbers)" << NORMAL << std::endl;
}

