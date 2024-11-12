/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:00:16 by ppuivif           #+#    #+#             */
/*   Updated: 2024/11/12 19:10:47 by ppuivif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Replace.hpp"

//parsing

//get_infile

//create_outfile

void	replace(std::string *line, std::string s1, std::string s2)
{
/*When find() (or similar functions) cannot find the specified substring or character, it returns std::string::npos to signal that the search was unsuccessful.
std::string::npos is typically a very large unsigned integer value, and it’s guaranteed to be a value that no valid string position could take.*/	
	while (std::size_t found = (*line).find(s1) != std::string::npos)
	{
//		erase()
//		insert()		
	}

}

int	main(int argc, char **argv)
{
	std::string line;
	
	if (argc != 4)
	{
		std::cerr << "wrong number of arguments" << std:: endl;
		return (0);
	}
	std::ifstream infile;//this line declares an input file stream object called infile
	infile.open(argv[1], std::ifstream::in);//open the file specified in argv[2] in read mode
	if (!infile.is_open())//true if the file specified in argv[2] is open and associated with the stream object infile
	{
		std::cerr << "infile couldn't be opened" << std:: endl;
		return (1);
	}
	std::string outfileName;
	outfileName = static_cast<std::string>(argv[1]) + ".replace";
	std::ofstream outfile;//this line declares an output file stream object called infile
	outfile.open(outfileName, std::ifstream::out);//open the file specified in argv[2] in read mode
	if (!outfile.is_open())//true if the file specified in argv[2] is open and associated with the stream object infile
	{
		std::cerr << outfileName << " couldn't be opened" << std:: endl;
		return (1);
	}
	while (std::getline(infile, line))
		replace(&line, static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]));
	
}



int main(int argc, char* argv[])
{
    char ch;
    std::ifstream ifin("E:\\testin.txt");
    std::ofstream ofin("G:\\testout.txt");

    if (!ifin) {
        std::cerr << "Input file could not be opened successfully.\n";
        return 1; // Non-zero return to indicate an error
    }
    if (!ofin) {
        std::cerr << "Output file could not be opened successfully.\n";
        return 1; // Non-zero return to indicate an error
    }

    // Copy characters from input to output
    while (ifin.get(ch)) {
        ofin.put(ch);
    }

    // No need to explicitly close files; they will close automatically on destruction
    return 0; // Return 0 to indicate successful execution
}

#include <iostream>
#include <fstream>
#include <string>

void customReplace(const std::string& inputFile, const std::string& outputFile, const std::string& s1, const std::string& s2) {
    // Open the input file for reading
    std::ifstream infile(inputFile);
    if (!infile.is_open()) {
        std::cerr << "Could not open input file for reading." << std::endl;
        return;
    }

    // Read the entire contents of the input file into a string
    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    // Manually create a new string with replacements
    std::string modifiedContent;
    std::size_t pos = 0;

    while (true) {
        // Find the next occurrence of s1
        std::size_t foundPos = content.find(s1, pos);

        if (foundPos == std::string::npos) {
            // If no more occurrences are found, append the rest of the content
            modifiedContent.append(content, pos, content.size() - pos);
            break;
        }

        // Append the part before the found occurrence of s1
        modifiedContent.append(content, pos, foundPos - pos);

        // Append s2 in place of s1
        modifiedContent.append(s2);

        // Move past the replaced substring
        pos = foundPos + s1.length();
    }

    // Open the output file for writing
    std::ofstream outfile(outputFile);
    if (!outfile.is_open()) {
        std::cerr << "Could not open output file for writing." << std::endl;
        return;
    }

    // Write the modified content to the output file
    outfile << modifiedContent;
    outfile.close();
}
