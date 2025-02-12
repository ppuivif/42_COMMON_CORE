/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:09:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/12 18:26:19 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype> //for isdigit

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter & rhs);
		ScalarConverter & operator=(ScalarConverter & rhs);
		~ScalarConverter(void);

		static bool	_isChar(std::string & input);
		static bool	_isInt(std::string & input);
		static bool	_isFloat(std::string & input);
		static bool	_isDouble(std::string & input);
		static bool	_isOther(std::string & input);

		static void _toChar(std::string & input);
		static void _toInt(std::string & input);
		static void _toFloat(std::string & input);
		static void _toDouble(std::string & input);
		static void _toOther(std::string & input);

	public:
		static void	convert(std::string & input);


};

#endif