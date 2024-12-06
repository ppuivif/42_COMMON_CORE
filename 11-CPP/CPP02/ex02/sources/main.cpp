/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/06 19:55:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
	#include <cstring>

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	// int		all_ones;
	// std::memset(&all_ones, 0xFF, sizeof (int));
	a.setRawBits(838285);
	Fixed		c(49.5f);
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
		std::cout << "c (" << c << ") != d (" << d << ") : true" << std::endl;

	std::cout << "a is " << a << std::endl;
	
	c = a + 10.4f;
	std::cout << "a + 10.4 = " << c << std::endl;
	
	c = a - 10.4f;
	std::cout << "a - 10.4 = " << c << std::endl;

	c = a * 10;
	std::cout << "a * 10 = " << c << std::endl;

	c = a / 10;
	std::cout << "a / 10 = " << c << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	
	std::cout << "b is " << b << std::endl;

	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	Fixed::min(c, d)++;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

//	std::cout << "lesser is : " << Fixed::min(a, b) << std::endl;
	std::cout << "greater is : " << Fixed::max(a, b) << std::endl;

	return (0);
}