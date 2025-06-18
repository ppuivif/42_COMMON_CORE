#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell{

	public:
		Fwoosh(){
			this->_name = "Fwoosh";
			this->_effects = "fwooshed";
		}
		Fwoosh(Fwoosh const & rhs) : ASpell(rhs){}
		Fwoosh & operator=(Fwoosh const & rhs){
			if (this != &rhs)
				this->ASpell::operator=(rhs);
			return (*this);
		}
		~Fwoosh(){}
		
		Fwoosh * clone() const{
			Fwoosh * clone = new Fwoosh(*this);
			return(clone);
		}

};

#endif