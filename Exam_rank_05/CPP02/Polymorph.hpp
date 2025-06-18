#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell{

	public:
		Polymorph(){
			this->_name = "Polymorph";
			this->_effects = "turner into a critter";
		}
		Polymorph(Polymorph const & rhs) : ASpell(rhs){}
		Polymorph & operator=(Polymorph const & rhs){
			if (this != &rhs)
				this->ASpell::operator=(rhs);
			return (*this);
		}
		~Polymorph(){}
		
		Polymorph * clone() const{
			Polymorph * clone = new Polymorph(*this);
			return(clone);
		}

};

#endif