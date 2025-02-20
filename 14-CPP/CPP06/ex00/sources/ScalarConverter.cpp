/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:45 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/20 20:41:41 by ppuivif          ###   ########.fr       */
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
	switch (index)
	{
		case 0 :
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
}

void	display(char c, long long int i, float f, double d, bool isValid, bool isZero, bool overflow)
{
    std::ostringstream stream;
	double intPartInDouble;
	float intPartInFloat;

//	(void)isZero;
//	if (isValid == false && (c <= 0 || c > 127))
	if (isZero == false && (c <= 0 || c > 127))
		std::cout << "char :\t " << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char :\t " << "non displayable" << std::endl;
	else
		std::cout << "char :\t " << "'" << c << "'" << std::endl;

	if (i < -2147483648 || i > 2147483647 || isValid == false)
		std::cout << "int :\t " << "impossible" << std::endl;
	else
		std::cout << "int :\t " << i << std::endl;
		
    // Check if the number has decimal places
	if (isValid == false || overflow == true)
		std::cout << "float :\t " << "impossible" << std::endl;
	else
	{
		if (modff(d, &intPartInFloat) == 0.0) //is fractionnal part equal to zero
			// Integer value: Force one decimal place
			stream << std::fixed << std::setprecision(1) << f;
		else
			// Non-integer: Use max precision to preserve all digits
			stream << std::fixed << std::setprecision(7) << f; //fixed is used to display number in decimal form
		std::cout << "float :\t " << stream.str() << "f" << std::endl;
		stream.str("");
		stream.clear();
	}

	if (isValid == false)
		std::cout << "double : " << "impossible" << std::endl;
	else
	{
		if (modf(d, &intPartInDouble) == 0.0) //is fractionnal part equal to zero
			stream << std::fixed << std::setprecision(1) << d; //fixed is used to display number in decimal form
		else
			stream << std::fixed << std::setprecision(15) << d;
		std::cout << "double : " << stream.str() << std::endl;
	}
}

void	ScalarConverter::convert(std::string const & input)
{
	int			index = 0;
	char		c = 0;
	long long int	i = 0;
	float		f = 0;
	double		d = 0;
	bool		isValid = true;
	bool		isZero = false;
	bool		overflow = false;

	bool array[] = {_isChar(input, &c), _isInt(input, &i, &isValid), _isFloat(input, &f, &isValid, &overflow, &isZero), _isDouble(input, &d, &isValid, &isZero)};
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
			std::cout << "Error : input \'" << input << "\' does not match with any type" << std::endl;
			return;
	}
	display(c, i, f, d, isValid, isZero, overflow);

}

bool	ScalarConverter::_isChar(std::string const & input, char *c)
{
	if (input.size() == 1 && !isdigit(input[0]))
	{
		*c = input[0];
		return(true);
	}
	return (false);
}

bool	ScalarConverter::_isInt(std::string const & input, long long int *i, bool *isValid)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;

 	*i = std::strtoll(str, &endptr, 10);
	//if out of range, errno is set to ERANGE, here don't used because we verify limits of int and not long long int
	//if a non digit behind digit, *endptr != '\0'
	if (*endptr == 0)
	{
		if (*i < -2147483648 || *i > 2147483647)
			*isValid = false;
		return(true);
	}
	return (false);
}

bool	ScalarConverter::_isFloat(std::string const & input, float *f, bool *isValid, bool *overflow, bool *isZero)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;
	double d = 0;

//	(void)*isZero;

 	if (!isspace(input[0]))
	{
		*f = std::strtof(str, &endptr);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
		if (static_cast<int>(*f) == 0 && !errno)
			*isZero = true;
		if (*endptr == 'f' && endptr[1] == 0)
		{
			if (errno)
				*isValid = false;
			return(true);
		}
		errno = 0;
		d = strtod(str, &endptr);
		if (d != INFINITY && d != -INFINITY && *endptr == '\0' && !errno && (d < -3.40282e38 || d > 3.40282e38))
			*overflow = true;
	}
	return (false);
}

bool	ScalarConverter::_isDouble(std::string const & input, double *d, bool *isValid, bool *isZero)
{
	const char *str = input.c_str();
	char *endptr;
	errno = 0;

	if (!isspace(input[0]) && \
	input.find("x") == std::string::npos && \
	input.find("X") == std::string::npos)
	{
		*d = std::strtod(str, &endptr);
	//to handle true zero
//		if (static_cast<int>(*d) == 0)
		if (static_cast<int>(*d) == 0 && !errno)
			*isZero = true;
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
