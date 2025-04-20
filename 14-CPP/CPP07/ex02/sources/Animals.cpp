#include "Animals.hpp"

Animals::Animals(){

}

Animals::Animals(std::string specie, std::string classe) : _specie(specie), _classe(classe){

}

Animals::~Animals(){

}

std::string Animals::getSpecie() const{
	return (this->_specie);
}

std::string Animals::getClasse() const{
	return (this->_classe);
}

std::ostream & operator<<(std::ostream & os, const Animals & animal){

	if (!animal.getSpecie().empty())
		os << animal.getSpecie() <<" is a " <<  animal.getClasse();
	return (os);
}