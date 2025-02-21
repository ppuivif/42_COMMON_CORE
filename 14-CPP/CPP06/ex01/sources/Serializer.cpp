/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:57:05 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/21 19:07:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	
}

Serializer::Serializer(Serializer & rhs)
{
	*this = rhs;
}

Serializer & Serializer::operator=(Serializer & rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	
}

uintptr_t Serializer::serialize(t_Data * ptr)
{
	uintptr_t result = 0;

	if (ptr)
	{
		result = reinterpret_cast<uintptr_t>(ptr);
		std::cout << "serialization realised" << std::endl;
	}
	else
		std::cout << "serialization impossible" << std::endl;
	return(result);
}

t_Data	* Serializer::deserialize(uintptr_t raw)
{
	t_Data	*ptr = NULL;

	ptr = reinterpret_cast<t_Data *>(raw);
	if (!ptr)
		std::cout << "deserialization failed" << std::endl;
	else
		std::cout << "deserialization realised" << std::endl;
	return (ptr);
}

void	Serializer::initStruct(t_Data * ptr)
{
	ptr->c = 'A';
	ptr->i = 1;
	ptr->f = 2.0f;
	ptr->d = 3.0;
}

void	Serializer::displayStructContent(t_Data const &data)
{
	std::cout << "char : \t " << data.c << std::endl;
	std::cout << "int : \t " << data.i << std::endl;
	std::cout << "float :  " << std::fixed << std::setprecision(1) << data.f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << data.d << std::endl;
}
