/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:09 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/10 11:15:03 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = i * scale;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	int scale = 1 << this->_bit;
	this->_value = roundf(f * scale);// roundf from cmath library
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return (*this);
}

float		Fixed::toFloat(void) const
{
	float	result = 0;
	float	tmp_float;
	int scale = 1 << this->_bit;
	tmp_float = (float)this->_value;//convert Fixed to "fake" float
	result = tmp_float / scale;//convert "fake" float to "real" float 
	return (result);
}

int		Fixed::toInt(void) const
{
	int result = 0;
	int scale = 1 << this->_bit;


//	result = this->_value >> this->_bit;//fonctionne

	result = this->_value / scale;
	return (result);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream &operator << (std::ostream &out, Fixed const &fx)
{
	out << fx.toFloat();
	return (out);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
