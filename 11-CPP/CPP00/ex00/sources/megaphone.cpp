/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:29:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/06 16:28:10 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv){
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLEFEEDBACK NOISE *";
	else{
		std::string str;
		str = argv[1];
		for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
    		std::cout << (char)toupper(*it);
	}
	std::cout << std::endl;
	return (0);
}