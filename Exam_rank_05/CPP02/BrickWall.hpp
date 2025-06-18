#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget{

	public:
		BrickWall(){
			this->_type = "Inconspicuous Red-brick Wall";
		}
		BrickWall(BrickWall const & rhs) : ATarget(rhs){}
		BrickWall & operator=(BrickWall const & rhs){
			if (this != &rhs)
				this->ATarget::operator=(rhs);
			return (*this);
		}
		~BrickWall(){}
		
		BrickWall * clone() const{
			BrickWall * clone = new BrickWall(*this);
			return(clone);
		}

};

#endif