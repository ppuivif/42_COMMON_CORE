#include "RPN.hpp"

int main(int argc, char **argv){

	RPN	rpn;
	if (rpn.parsingArguments(argc, argv) == 1)
		return (1);
	rpn.displayResult();
	return (0);
}