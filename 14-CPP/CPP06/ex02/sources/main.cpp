/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:31:39 by ppuivif           #+#    #+#             */
/*   Updated: 2025/02/22 19:18:25 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand((unsigned) time(NULL));
		
	Base	*p;

	p = generate();
	identify(p);
	identify(*p);

	delete p;
	return (0);
}