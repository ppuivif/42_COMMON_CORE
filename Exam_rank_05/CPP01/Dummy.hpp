#ifndef TARGET_HPP
# define TARGET_HPP

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget{

	public:
		Dummy(){
			this->_type = "Target Practice Dummy";
		}
		Dummy(Dummy const & rhs) : ATarget(rhs){}
		Dummy & operator=(Dummy const & rhs){
			if (this != &rhs)
				this->ATarget::operator=(rhs);
			return (*this);
		}
		~Dummy(){}
		
		Dummy * clone() const{
			Dummy * clone = new Dummy(*this);
			return(clone);
		}

};

#endif