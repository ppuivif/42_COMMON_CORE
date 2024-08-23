#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

namespace Var1{
	int		i = 1;
	char	c = 'a';
}

namespace Var2{
	int		i = 2;
	char	c = 'b';
}

// : operateur de resolution de portee

int main() {
	char	buff[512];

//	string& buff2(buff);
	cout << "Hello World1" << endl;
	printf("%s\n", "Hello World2");
	std::cout << "Input a word : ";
	std::cin >> buff;
	std::cout << "You entered : " << buff << std::endl;
	printf("Var1::i : %d\n", Var1::i);
	printf("Var2::i : %d\n", Var2::i);
	return (0);
}