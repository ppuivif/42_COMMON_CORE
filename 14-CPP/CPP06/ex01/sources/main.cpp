/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:08:49 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/21 19:09:51 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	t_Data		initialData;
	uintptr_t	raw;
	t_Data		*finalData;

	Serializer::initStruct(&initialData);
	std::cout << "address of initialData : " << &initialData << std::endl;
	Serializer::displayStructContent(initialData);

	raw = Serializer::serialize(&initialData);
	if (!raw)
		return (1);

	finalData = Serializer::deserialize(raw);
	if (!finalData)
		return (1);
	std::cout << "address of finalData : " << finalData << std::endl;
	Serializer::displayStructContent(*finalData);
	
	return (0);
}