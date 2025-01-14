/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/10 16:38:45 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
//	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int i)
{
//	std::cout << "Int constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = i * scale;
}

Fixed::Fixed(const float f)
{
//	std::cout << "Float constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = roundf(f * scale);
}

Fixed::Fixed(const Fixed &src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator = (const Fixed &src)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return (*this);
}

float	Fixed::toFloat(void) const
{
	float result = 0;
	int scale = 1 << this->_bit;
	result = (float)this->_value / scale;
	return (result);
}

int	Fixed::toInt(void) const
{
	int result = 0;
	int scale = 1 << this->_bit;
	result = this->_value / scale;
	return (result);
}

int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream &operator << (std::ostream &out, const Fixed &fx)
{
	out << fx.toFloat();
	return (out);
}

bool	Fixed::operator < (const Fixed &nb) const
{
	if (this->_value < nb._value)
		return (true);
	return (false);
}

bool	Fixed::operator > (const Fixed &nb) const
{
	if (this->_value > nb._value)
		return (true);
	return (false);
}

bool	Fixed::operator <= (const Fixed &nb) const
{
	if (this->_value <= nb._value)
		return (true);
	return (false);
}

bool	Fixed::operator >= (const Fixed &nb) const
{
	if (this->_value >= nb._value)
		return (true);
	return (false);
}

bool	Fixed::operator == (const Fixed &nb) const
{
	if (this->_value == nb._value)
		return (true);
	return (false);
}

bool	Fixed::operator != (const Fixed &nb) const
{
	if (this->_value != nb._value)
		return (true);
	return (false);
}

Fixed	Fixed::operator + (const Fixed &nb) const
{
	Fixed	result;
	
	result._value = this->_value + nb._value;
	return (result);
}

Fixed	Fixed::operator - (const Fixed &nb) const
{
	Fixed	result;
	
	result._value = this->_value - nb._value;
	return (result);
}

Fixed	Fixed::operator * (const Fixed &nb) const
{
	Fixed	result;
	int scale = 1 << this->_bit;
	
	result._value = ((long int)(this->_value * nb._value)) / scale;
	return (result);
}

Fixed	Fixed::operator / (const Fixed &nb) const
{
	Fixed	result;
	int scale = 1 << this->_bit;
	
	result._value = (((long int)this->_value) * scale) / nb._value;
	return (result);
}

Fixed	Fixed::operator ++ (int) //prefix
{
	Fixed	result;

	result = *this;
	this->_value += 1;
	return (result);
}

Fixed	Fixed::operator ++ (void) //postfix
{
	Fixed	result;
	
	this->_value += 1;
	result = *this;
	return (result);
}

Fixed	Fixed::operator -- (int) //prefix
{
	Fixed	result;

	result = *this;
	this->_value -= 1;
	return (result);
}

Fixed	Fixed::operator -- (void) //postfix
{
	Fixed	result;
	
	this->_value -= 1;
	result = *this;
	return (result);
}

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
	return;
}