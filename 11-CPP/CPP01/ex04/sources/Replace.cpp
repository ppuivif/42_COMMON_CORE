/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:20:06 by ppuivif           #+#    #+#             */
/*   Updated: 2024/12/02 09:47:47 by ppuivif          ###   ########.fr       */
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
	this->infileStream.open(infile.c_str(), std::ifstream::in);//open the file specified in argv[2] in read mode
	if (!this->infileStream.is_open())//true if the file specified in argv[2] is not open (file associated with the stream object infile)
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
	this->outfileStream.open(outfile.c_str(), std::ofstream::out);
	if (!this->outfileStream.is_open())//true if the file specified in argv[1] is not open (file associated with the stream object outfile)
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
		this->outfileStream << line << std::endl;//copy the line in the outfileStream
	}
}

void	Replace::replaceStrings(std::string *line, std::string s1, std::string s2)
{
	
/*When find() (or similar functions) cannot find the specified substring or character, it returns std::string::npos to signal that the search was unsuccessful.
std::string::npos is typically a very large unsigned integer value, and it’s guaranteed to be a value that no valid string position could take.*/	
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
