/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:29:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/09/23 09:53:08 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLEFEEDBACK NOISE *" << std::endl;
	else
	{
		for (int j = 1 ; argv[j] ; j++){
			for (int i = 0 ; argv[j][i] ; i++){
				if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
					argv[j][i] -= 32;
				if (argv[j][i] != ' ')
					std::cout << argv[j][i];
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}