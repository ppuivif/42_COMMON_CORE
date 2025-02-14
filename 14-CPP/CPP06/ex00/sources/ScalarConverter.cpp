/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:45 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/14 21:20:28 by ppuivif          ###   ########.fr       */
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

void	cast(int index, char *c, long int *i, float *f, double *d)
{
//	void	*ptr = NULL;
	
	switch (index)
	{
		case 0 :
//			ptr = &c;
			*i = static_cast<int>(*c);
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
			*i = static_cast<int>(*f);
			*d = static_cast<double>(*f);
		case 3 :
			*c = static_cast<char>(*d);
			*i = static_cast<int>(*d);
			*f = static_cast<float>(*d);
	}
/*	*c = static_cast<char>(*ptr);
	*f = static_cast<float>(*ptr);
	*d = static_cast<double>(*ptr);*/
}

void	display(char c, int i, float f, double d)
{
    std::ostringstream stream;

	if (c < 0 || c > 127)
		std::cout << "char :\t " << "impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char :\t " << "'" << c << "'" << std::endl;
	else
		std::cout << "char :\t " << "non printable" << std::endl;

	std::cout << "int :\t " << i << std::endl;

    // Check if the number has decimal places
	if (f == i)
        // Integer value: Force one decimal place
		stream << std::fixed << std::setprecision(1) << f;
	else
        // Non-integer: Use max precision to preserve all digits
		stream << f;
	std::cout << "float :\t " << stream.str() << "f" << std::endl;
	stream.str("");
	stream.clear();

	if (d == i)
		stream << std::fixed << std::setprecision(1) << f;
	else
		stream << f;
	std::cout << "double : " << stream.str() << std::endl;
}

void	ScalarConverter::convert(std::string & input)
{
	int			index = 0;
	char		c;
	long int	i = 0;
	float		f = 0;
	double		d = 0;
	bool		isOOR = false; //is Out Of Range
	bool		isOther = false;

	bool array[] = {_isChar(input, &c), _isInt(input, &i, &isOOR), _isFloat(input, &f, &isOther), _isDouble(input, &d, &isOther), isOther};
	for (; index < 5; index++)
	{
		if(array[index] == true)
			break;
	}
	switch (index) //pb with hexadecimal notation and see precision for displaying result
	{
		case 0 :
			cast(index, &c, &i, &f, &d);
			break;
		case 1 :
			if (isOOR == false)
			{
				std::cout << i << " is an int" << std::endl;
				cast(index, &c, &i, &f, &d);
			}
			else
				std::cout << "input " << input << " is not valid" << std::endl;
			break;
		case 2 :
			std::cout << f << " is a float" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		case 3 :
			std::cout << d << " is a double" << std::endl;
			cast(index, &c, &i, &f, &d);
			break;
		case 4 : //not required
			std::cout << input << " is other" << std::endl;
			break;
		default :
			std::cout << "input " << input << " is not valid" << std::endl;
			return;
	}
	display(c, i, f, d);

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

bool	ScalarConverter::_isInt(std::string & input, long int *i, bool *isOOR)
{
	const char *str = input.c_str();
	char *endptr;

 	*i = strtol(str, &endptr, 10);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
	if (!errno && *endptr == 0)
	{
		if (*i < -2147483648 || *i > 2147483647)
			*isOOR = true;
		return(true);
	}
	return (false);
}

bool	ScalarConverter::_isFloat(std::string & input, float *f, bool *isOther)
{
	const char *str = input.c_str();
	char *endptr;

 	*f = strtof(str, &endptr);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
	if (!errno && *endptr == 'f' && endptr[1] == 0)
	{
		if (!isnan(*f) && *f != INFINITY && *f != -INFINITY)
			return(true);
		*isOther = true;
	}
	return (false);
}

bool	ScalarConverter::_isDouble(std::string & input, double *d,  bool *isOther)
{
	const char *str = input.c_str();
	char *endptr;

 	*d = strtod(str, &endptr);
	//if out of range, errno is set to ERANGE
	//if a non digit behind digit, *endptr != '\0'
	if (!errno && *endptr == '\0')
	{
		if (!isnan(*d) && *d != INFINITY && *d != -INFINITY)
			return(true);
		*isOther = true;
	}
	return (false);
}
