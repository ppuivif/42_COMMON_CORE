/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:29:35 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/08 15:37:28 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string message = "HI THIS IS BRAIN";
	std::string *stringPTR = &message;
	std::string &stringREF = message;

	std::cout << "memory address of message is : " << &message << std::endl;
	std::cout << "memory address of pointer stringPTR to message is : " << &stringPTR << std::endl;
	std::cout << "memory address of reference stringREF to message is : " << &stringREF << std::endl << std::endl;
    
	std::cout << "value of memory is : " << message << std::endl;
	std::cout << "value pointed by stringPTR is : " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF is : " << stringREF << std::endl;
}