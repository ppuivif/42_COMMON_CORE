/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:25:27 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/21 11:46:27 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Heap Zombie (new)");
	randomChump("Stack Zombie (chump)");
	delete heapZombie;
	return (0);
}
