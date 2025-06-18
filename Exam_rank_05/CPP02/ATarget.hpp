#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget{

	public:
		ATarget(){}
		ATarget(ATarget const & rhs){
			*this = rhs;
		}
		ATarget & operator=(ATarget const & rhs){
			if (this != &rhs){
				this->_type = rhs._type;
			}
			return (*this);
		}
		ATarget (std::string type): _type(type){}
		virtual ~ATarget(){}
		
		std::string const & getType() const{
			return (this->_type);
		}
		virtual ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & spell) const;

	protected:
		std::string _type;

};

#endif