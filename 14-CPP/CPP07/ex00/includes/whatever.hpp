/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:47:00 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/25 11:13:04 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>

void	swap(T & arg1, T & arg2){

	T	tmp = arg1;
	
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>

T const & max(T const & arg1, T const & arg2){
	return(arg1>arg2 ? arg1 : arg2);
}

template<typename T>

T const & min(T const & arg1, T const & arg2){
	return(arg1<arg2 ? arg1 : arg2);
}

#endif