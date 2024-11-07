/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:29:30 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/07 09:34:38 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv){
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLEFEEDBACK NOISE *";
	else{
		std::string str;
		for (int i = 1; argv[i]; i++){
			str = argv[i];
			for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
    			std::cout << (char)toupper(*it);
		}
	}
	std::cout << std::endl;
	return (0);
}