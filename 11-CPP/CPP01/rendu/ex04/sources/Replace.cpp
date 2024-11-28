/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:20:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/28 08:27:10 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(void)
{
	return;
}

int	Replace::parsing(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std:: endl;
		return (1);
	}
	if (argv[1][0] == 0)
	{
		std::cerr << "filename is empty" << std:: endl;
		return (1);
	}
	if (argv[2][0] == 0)
	{
		std::cerr << "string to replace is empty" << std:: endl;
		return (1);
	}
	return (0);	
}

int Replace::getInfileStream(std::string infile)
{
	this->infileStream.open(infile.c_str(), std::ifstream::in);
	if (!this->infileStream.is_open())
	{
		std::cerr << "infile couldn't be opened or do not exist" << std:: endl;
		return (1);
	}
	return (0);
}

int	Replace::createOutfileStream(std::string infile)
{
	std::string outfile;

	outfile = infile + ".replace";
	this->outfileStream.open(outfile.c_str(), std::ifstream::out);
	if (!this->outfileStream.is_open())
	{
		std::cerr << outfile << " couldn't be created" << std:: endl;
		return (1);
	}
	return (0);
}

void	Replace::replaceStringsAndCopyContent(std::string s1, std::string s2)
{
	std::string		line;

	while (std::getline(this->infileStream, line))
	{
		this->replaceStrings(&line, s1, s2);
		this->outfileStream << line << std::endl;
	}
}

void	Replace::replaceStrings(std::string *line, std::string s1, std::string s2)
{
	std::size_t pos = 0;
	
	while ((pos = (*line).find(s1, pos)) != std::string::npos)
	{
		(*line).erase(pos, s1.length());
		(*line).insert(pos, s2);
		pos += s2.length();
	}
}

void	Replace::closeStreams(void)
{
	this->infileStream.close();
	this->outfileStream.close();
}

Replace::~Replace(void)
{
	return;
}