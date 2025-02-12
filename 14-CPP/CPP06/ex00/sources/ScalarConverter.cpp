/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:45 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/12 18:45:32 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor ScalarConverter called" << std::endl; 
}

ScalarConverter::ScalarConverter(ScalarConverter & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor ScalarConverter called" << std::endl; 
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter & rhs)
{
	(void)rhs;
	std::cout << "Assignment operator ScalarConverter called" << std::endl;
	return(*this);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor ScalarConverter called" << std::endl; 
}

void	ScalarConverter::convert(std::string & input)
{
	int	i = 0;
	bool array[] = {_isChar(input)};
	for(; i < 5; i++)
	{
		if(array[i] == true)
			break;
	}
	switch (i)
	{
		case 0 :
			std::cout << input << " is a char" << std::endl;
			break;

		default :
			std::cout << "input " << input << " is not valid" << std::endl;
	}

}

bool	ScalarConverter::_isChar(std::string & input)
{
	if (input.size() == 1 && !isdigit(input[0]) && isprint(input[0]))
		return(true);
	return (false);
}
