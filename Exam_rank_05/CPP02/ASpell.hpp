#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>

class ATarget;

class ASpell{

	public:
		ASpell(){}
		ASpell(ASpell const & rhs){
			*this = rhs;
		}
		ASpell & operator=(ASpell const & rhs){
			if (this != &rhs){
				this->_name = rhs._name;
				this->_effects = rhs._effects;
			}
			return (*this);
		}
		ASpell (std::string name, std::string effects): _name(name), _effects(effects){}
		virtual ~ASpell(){}
		
		std::string const & getName() const{
			return (this->_name);
		}
		std::string const & getEffects() const{
			return (this->_effects);
		}
		virtual ASpell * clone() const = 0;
		void launch(ATarget const & target) const;

	protected:
		std::string _name;
		std::string	_effects;

};

#endif