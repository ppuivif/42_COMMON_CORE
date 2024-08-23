#include <iostream>
#include "Sample.class.hpp"

using namespace std;

Sample::Sample(void){

    cout << "constructor called" << endl;
    return;

}

Sample::~Sample(void){

    cout << "destructor called" << endl;
    return;

}

void    Sample::function(void){

    cout << "function is called" << endl;
	return;

}