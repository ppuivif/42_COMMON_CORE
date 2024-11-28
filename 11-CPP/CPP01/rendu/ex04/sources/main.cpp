/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:00:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/27 14:53:23 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	Replace 		replace;
	
	if (replace.parsing(argc, argv))
		return (1);

	const std::string	infile(argv[1]);
	const std::string	s1(argv[2]);
	const std::string	s2(argv[3]);
	
	if (replace.getInfileStream(infile))
		return (1);
	
	if (replace.createOutfileStream(infile))
		return (1);
	
	replace.replaceStringsAndCopyContent(s1, s2);
	
	replace.closeStreams();

	return (0);
}
