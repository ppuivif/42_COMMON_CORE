#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell{

	public:
		Fireball(){
			this->_name = "Fireball";
			this->_effects = "burnt to a crisp";
		}
		Fireball(Fireball const & rhs) : ASpell(rhs){}
		Fireball & operator=(Fireball const & rhs){
			if (this != &rhs)
				this->ASpell::operator=(rhs);
			return (*this);
		}
		~Fireball(){}
		
		Fireball * clone() const{
			Fireball * clone = new Fireball(*this);
			return(clone);
		}

};

#endif