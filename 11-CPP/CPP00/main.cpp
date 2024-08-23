#include <iostream>
#include "Sample.class.hpp"

using namespace std;

int main(){

	Sample instance;
	instance.c = 'a';
	instance.i = 42;
	cout << "instance.c value is : " << instance.c << endl;
	cout << "instance.i value is : " << instance.i << endl;
	instance.function();
	return (0);

}