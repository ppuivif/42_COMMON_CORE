/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:35:46 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/13 11:48:29 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &rhs);
		Brain &operator=(const Brain &rhs);
		~Brain(void);

		const std::string *getIdeas(void) const;

	protected:
		std::string _ideas[100];
};

#endif