#include <iostream>
#include "Sample.class.hpp"

using namespace std;

// eclaircir declaration et initialisation

Sample::Sample(int p1, char p2) : i(p1), c(p2) {

    cout << "constructor called" << endl;
    cout << "i = " << this->i << endl; 
    cout << "c = " << this->c << endl;

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