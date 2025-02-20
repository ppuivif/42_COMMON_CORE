/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:09:34 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/20 20:13:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype> //for isdigit
#include <cstdlib> //for strtoll
#include <cerrno> //for errno
#include <math.h> //for nan and modf
#include <iomanip> //for setprecision
#include <sstream> //for ostringstream

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter & rhs);
		ScalarConverter & operator=(ScalarConverter & rhs);
		~ScalarConverter(void);

		static bool	_isChar(std::string const & input, char *c);
		static bool	_isInt(std::string const & input, long long int *i, bool *isValid);
		static bool	_isFloat(std::string const & input, float *f, bool *isValid, bool *overflow, bool *isZero);
		static bool	_isDouble(std::string const & input, double *d, bool *isValid, bool *isZero);

		static void _toChar(std::string const & input);
		static void _toInt(std::string const & input);
		static void _toFloat(std::string const & input);
		static void _toDouble(std::string const & input);
		static void _toOther(std::string const & input);

	public:
		static void	convert(std::string const & input);


};

#endif
