/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:30:52 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/20 20:21:20 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : bad number of arguments" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	if (input.empty())
	{
		std::cout << "Error : argument is empty" << std::endl;
		return (1);
	}
	ScalarConverter::convert(input);
//	ScalarConverter::convert(argv[1]);
	return (0);
}