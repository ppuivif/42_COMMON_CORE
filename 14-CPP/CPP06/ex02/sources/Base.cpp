/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:06:46 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/22 19:17:35 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	
}

Base	* generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void	identify(Base * p)
{
	if (!p)
	{
		std::cout << "Pointer point to nothing" << std::endl;
		return;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer point to an object of classe A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer point to an object of classe B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer point to an object of classe C" << std::endl;
	else
		std::cout << "Pointer point to an object of unknown class" << std::endl;
}

void	identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference designate an object of classe A" << std::endl;
		return;
	}
	catch(const std::exception & bc)
	{

	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference designate an object of classe B" << std::endl;
		return;
	}
	catch(const std::exception & bc)
	{

	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference designate an object of classe C" << std::endl;
		return;
	}
	catch(const std::exception & bc)
	{

	}
	std::cout << "Reference designate an object of unknown class" << std::endl;
}
