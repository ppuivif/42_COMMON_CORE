/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:02:32 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/28 08:26:16 by ppuivif          ###   ########.fr       */
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
		int		getInfileStream(const std::string infile);
		int		createOutfileStream(std::string infile);
		void	replaceStringsAndCopyContent(std::string s1, std::string s2);
		void	replaceStrings(std::string *line, std::string s1, std::string s2);
		void	closeStreams(void);

	private:
		std::ifstream	infileStream;
		std::ofstream	outfileStream;
};

#endif