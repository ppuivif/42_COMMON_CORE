#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstring> //for npos
#include <cstdlib> //for atoi

#ifndef GREEN
# define GREEN "\033[32m"
#endif
#ifndef BOLD_RED
# define BOLD_RED "\033[1;31m"
#endif
#ifndef BOLD
# define BOLD "\033[1m"
#endif
#ifndef NORMAL
# define NORMAL "\033[0m"
#endif

class RPN{

	public:
		RPN();
		~RPN();
		RPN(RPN const & rhs);
		RPN & operator=(RPN const & rhs);

		int		parsingArguments(int argc, char **argv);
		int		loadCharacters(char *argv);
		int		calculate(char character);
		void	displayResult();

	private:
		std::stack<int> _stack;

};

#endif