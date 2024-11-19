/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/19 19:33:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = i * scale;
	return;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = roundf(f * scale);
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
//	this->_value = src._value; // alternative solution where assignment operator not called
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return (*this);
}
//	a = 1234.4321f;

{
	float result = 0;
	int scale = 1 << this->_bit;
	result = (float)this->_value / scale; 
	return (result);
}

int		Fixed::toInt(void) const
{
	int result = 0;
	result = (int)toFloat();
	return (result);
}

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}