#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

namespace var{
    char    c('a');
    int     i(1);
    string  str("Hello World3");
}


int main(){
    char    buff[512];

    std::cout << "Hello World1" << endl;
    printf("Hello World2\n");
    std::cout << "c value is : " << var::c << endl;
    std::cout << "i value is : " << var::i << endl;
    std::cout << "str value is : " << var::str << endl;
    std::cout << "Input a word : ";
    std::cin >> buff;
    std::cout << "You entered the world : " << buff << endl;
    return (0);
}