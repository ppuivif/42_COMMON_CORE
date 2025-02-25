/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:35:13 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/25 18:58:41 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>

void	displayContent(T const & content){
	std::cout << content << std::endl;
}

template <typename T>

void	iter(T * array, size_t size, void (*function)(T const &)){

	for (size_t index = 0; index < size; index++)
		function(array[index]);
}

#endif