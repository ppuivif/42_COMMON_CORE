#ifndef ANIMALS_HPP
# define ANIMALS_HPP

#include <iostream>
#include <string>


class Animals{

	public:
		Animals();
		Animals(std::string specie, std::string classe);
		~Animals();

		std::string getSpecie() const;
		std::string getClasse() const;


	private:
		std::string	_specie;
		std::string	_classe;

};

std::ostream & operator<<(std::ostream & os, const Animals & animal);

#endif