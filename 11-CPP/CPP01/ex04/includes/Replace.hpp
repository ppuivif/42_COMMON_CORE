/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:02:32 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/13 16:58:10 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#ifndef REPLACE_HPP
# define REPLACE_HPP

class	Replace
{
	public:
		Replace(void);
		~Replace(void);

		int		parsing(int argc, char **argv);
		int		getInfileStream(std::string infile);
		int		createOutfileStream(std::string infile);
		void	replaceStringsAndCopyContent(std::string s1, std::string s2);
		void	replaceStrings(std::string *line, std::string s1, std::string s2);
		void	closeStreams(void);

	private:
		std::ifstream	infileStream;//this line declares an input file stream object called infileStream
		std::ofstream	outfileStream;//this line declares an output file stream object called outfileStream	
};

#endif