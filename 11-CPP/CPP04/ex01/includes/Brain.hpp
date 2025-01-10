/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:35:46 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/10 19:06:00 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &rhs);
		Brain &operator=(Brain const &rhs);
		~Brain(void);

		std::string getIdea(int index) const;
		void setIdea(std::string const idea);

	private:
		std::string	_ideas[100];
};

#endif