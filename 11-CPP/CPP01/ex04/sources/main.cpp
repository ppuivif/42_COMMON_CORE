/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:00:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/13 13:22:06 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

int	parsing(int argc, std::string s1, std::string s2)
{
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std:: endl;
		return (1);
	}
	if (s1.empty() || s2.empty())
	{
		std::cerr << "string to replace / string to insert is empty" << std:: endl;
		return (1);
	}
	return (0);	
}

//get_infile

//create_outfile

void	replace(std::string *line, std::string s1, std::string s2)
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

int	main(int argc, char **argv)
{
	std::string line;
    char        c;
	std::string s1 = static_cast<std::string>(argv[2]);
	std::string s2 = static_cast<std::string>(argv[3]);
	std::ifstream infilestream;//this line declares an input file stream object called infile
	std::ofstream outfilestream;//this line declares an output file stream object called outfile
	std::string outfile;
	
	if (parsing(argc, s1, s2))
		return (1);

	infilestream.open(s1, std::ifstream::in);//open the file specified in argv[2] in read mode
	if (!infilestream.is_open())//true if the file specified in argv[2] is open and associated with the stream object infile
	{
		std::cerr << "infile couldn't be opened" << std:: endl;
		return (1);
	}
	outfile = static_cast<std::string>(argv[1]) + ".replace";
	outfilestream.open(outfile, std::ifstream::out);//open the file specified in argv[2] in read mode
	if (!outfile.is_open())//true if the file specified in argv[2] is open and associated with the stream object infile
	{
		std::cerr << outfileName << " couldn't be opened" << std:: endl;
		return (1);
	}
	while (std::getline(infile, line))
    {
		replace(&line, static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]));
		std::cout << "line : " << line << std::endl;
		outfile << line << std::endl;//copy the line in the outfile
	}
	infile.close();
    outfile.close();
    return (0);
}
