/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:45 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/18 19:48:30 by ppuivif          ###   ########.fr       */
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

void	cast(int index, char *c, long long int *i, float *f, double *d)
{
//	void	*ptr = NULL;
	
	switch (index)
	{
		case 0 :
//			ptr = &c;
			*i = static_cast<long long int>(*c);
			*f = static_cast<float>(*c);
			*d = static_cast<double>(*c);
			break;
		case 1 :
			*c = static_cast<char>(*i);
			*f = static_cast<float>(*i);
			*d = static_cast<double>(*i);
			break;
		case 2 :
			*c = static_cast<char>(*f);
			*d = static_cast<double>(*f);
			*i = static_cast<long long int>(*f);
			break;
		case 3 :
			*c = static_cast<char>(*d);
			*i = static_cast<long long int>(*d);
			*f = static_cast<float>(*d);
			break;
	}
/*	*c = static_cast<char>(*ptr);
	*f = static_cast<float>(*ptr);
	*d = static_cast<double>(*ptr);*/
}

void	display(char c, long long int i, float f, double d)
{
    std::ostringstream stream;

	std::cout << "char :\t " << "'" << c << "'" << std::endl;

//	condition si c = 0 non out of range;

	if (c <= 0 || c > 127 || \
	(isnan(f) || f == INFINITY || f == -INFINITY) || \
	(isnan(d) || d == INFINITY || d == -INFINITY))
		std::cout << "char :\t " << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char :\t " << "non printable" << std::endl;
	else
		std::cout << "char :\t " << "'" << c << "'" << std::endl;

//	if ((!isnan(f) && f != INFINITY && f != -INFINITY) || \
//	(!isnan(d) && d != INFINITY && d != -INFINITY))
	if (i >= -2147483648 && i <= 2147483647)
		std::cout << "int :\t " << i << std::endl;
	else
		std::cout << "int :\t " << "impossible" << std::endl;
		
    // Check if the number has decimal places
/*	if (f == i)
        // Integer value: Force one decimal place
		stream << std::fixed << std::setprecision(1) << f;
	else
        // Non-integer: Use max precision to preserve all digits
		stream << f;
	std::cout << "float :\t " << stream.str() << "f" << std::endl;
	stream.str("");
	stream.clear();*/

//	if (f == i)
//		std::cout << "float :\t " << std::setprecision(1) << f << "f" << std::endl;
//	else
	std::cout << "float :\t " << std::setprecision(30) << f << "f" << std::endl;

//	if (d == i)
//		stream << std::fixed << std::setprecision(1) << f;
//	else
//		stream << f;
//	std::cout << "double : " << stream.str() << std::endl;

//	if (d == i)
//		std::cout << "double : " << std::setprecision(1) << d << std::endl;
//	else
	std::cout << "double : " << std::setprecision(50) << d << std::endl;
}

void	ScalarConverter::convert(std::string & input)
{
	int			index = 0;
	char		c = 0;
	long long int	i = 0;
	float		f = 0;
	double		d = 0;
	bool		isValid = true;

	bool array[] = {_isChar(input, &c), _isInt(input, &i, &isValid), _isFloat(input, &f, &isValid), _isDouble(input, &d, &isValid)};
	for (; index < 5; index++)
	{
		if(array[index] == true)
			break;
	}
	switch (index) //see precision for displaying result
	{
		case 0 :
			std::cout << c << " is a char" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		case 1 :
			std::cout << i << " is an int" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		case 2 :
			std::cout << f << " is a float" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		case 3 :
			std::cout << d << " is a double" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		default :
			isValid = false;
			break;
	}
	if (isValid == true)
		display(c, i, f, d);
	else
		std::cout << "input " << input << " is not valid" << std::endl;

}

bool	ScalarConverter::_isChar(std::string & input, char *c)
{
	if (input.size() == 1 && !isdigit(input[0]) && isprint(input[0]))
	{
		*c = input[0];
		return(true);
	}
	return (false);
}

bool	ScalarConverter::_isInt(std::string & input, long long int *i, bool *isValid)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;

 	*i = strtol(str, &endptr, 10);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
	if (!errno && *endptr == 0)
	{
		if (*i < -2147483648 || *i > 2147483647)
			*isValid = false;
		return(true);
	}
	return (false);
}

bool	ScalarConverter::_isFloat(std::string & input, float *f, bool *isValid)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;

	(void)*isValid;

 	if (!isspace(input[0]))
	{
		*f = strtof(str, &endptr);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
		if (*endptr == 'f' && endptr[1] == 0)
		{
/*			if (errno == ERANGE)
				*isValid = false;*/
			return(true);
		}	
	}
	return (false);
}

bool	ScalarConverter::_isDouble(std::string & input, double *d, bool *isValid)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;

	if (!isspace(input[0]) && \
	input.find("x") == std::string::npos && \
	input.find("X") == std::string::npos)
	{
		*d = strtod(str, &endptr);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
		if (*endptr == '\0')
		{
			if (errno)
				*isValid = false;
			return(true);
		}	
	}
	return (false);
}
