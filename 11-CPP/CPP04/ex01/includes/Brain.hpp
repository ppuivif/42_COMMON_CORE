/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:35:46 by ppuivif           #+#    #+#             */
/*   Updated: 2025/01/09 08:57:16 by ppuivif          ###   ########.fr       */
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

		const std::string *getIdeas(void) const;

	protected:
		std::string	_ideas[100];
};

#endif