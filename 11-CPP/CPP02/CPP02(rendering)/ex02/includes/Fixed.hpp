/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:37:12 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/02 10:00:40 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

	public:
		Fixed(void);
		Fixed(const int	i);
		Fixed(const float f);
		Fixed(const Fixed &src);
		Fixed 	&operator = (const Fixed &src);
		~Fixed(void);
		
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

		bool			operator < (const Fixed &nb) const;
		bool			operator > (const Fixed &nb) const;
		bool			operator <= (const Fixed &nb) const;
		bool			operator >= (const Fixed &nb) const;
		bool			operator == (const Fixed &nb) const;
		bool			operator != (const Fixed &nb) const;
		Fixed			operator + (const Fixed &nb) const;
		Fixed			operator - (const Fixed &nb) const;
		Fixed			operator * (const Fixed &nb) const;
		Fixed			operator / (const Fixed &nb) const;
		Fixed			operator ++ (int);
		Fixed			operator ++ (void);
		Fixed			operator -- (int);
		Fixed			operator -- (void);
		static Fixed	min(Fixed &f1, Fixed &f2);
		static Fixed	min(const Fixed &f1, const Fixed &f2);
		static Fixed	max(Fixed &f1, Fixed &f2);
		static Fixed	max(const Fixed &f1, const Fixed &f2);
		
	private:
		int					_value;
		static const int	_bit = 8;
};

	std::ostream &operator << (std::ostream &out, const Fixed &fx);

#endif
