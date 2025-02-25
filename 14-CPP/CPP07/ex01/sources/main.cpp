/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:01 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/25 18:48:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(){

	int 		array1[] = {0, 1, 2, 3, 4, 5};
	float 		array2[] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f};
	std::string	array3[] = {"one", "two", "three", "for"};

	iter(array1, 6, displayContent<int>);
	std::cout << std::endl;
	iter(array2, 5, displayContent<float>);
	std::cout << std::endl;
	iter(array3, 4, displayContent<std::string>);

	return (0);
}