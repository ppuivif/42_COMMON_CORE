/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/10 11:23:13 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	#include <cstring>

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	
	std::cout << "b is " << b << std::endl;

/*	Fixed		c(49.5f);
	Fixed		d(50.5f);
	if (c < d)
		std::cout << "c (" << c << ") < d (" << d << ") : true" << std::endl;
	if (c > d)
		std::cout << "c (" << c << ") > d (" << d << ") : true" << std::endl;
	if (c <= d)
		std::cout << "c (" << c << ") <= d (" << d << ") : true" << std::endl;
	if (c >= d)
		std::cout << "c (" << c << ") >= d (" << d << ") : true" << std::endl;
	if (c == d)
		std::cout << "c (" << c << ") == d (" << d << ") : true" << std::endl;
	if (c != d)
		std::cout << "c (" << c << ") != d (" << d << ") : true" << std::endl;*/

/*	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	Fixed::min(c, d)++;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;*/

//	std::cout << "lesser is : " << Fixed::min(a, b) << std::endl;
	std::cout << "greater between a(" << a << ") and b(" << b << ") is : " << Fixed::max(a, b) << std::endl;

/*	a.setRawBits(42.5f);
	Fixed	d(10);
	std::cout << "a is " << a << std::endl;
	
	c = a + d;
	std::cout << "a + d = " << c << std::endl;
	
	c = a - df;
	std::cout << "a - d = " << c << std::endl;

	c = a * d;
	std::cout << "a * d = " << c << std::endl;

	c = a / d;
	std::cout << "a / d = " << c << std::endl;*/

	return (0);
}