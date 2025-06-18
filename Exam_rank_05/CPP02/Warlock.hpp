#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <map>
#include "SpellBook.hpp"

class ASpell;

class ATarget;

class SpellBook;

class Warlock{

	public:
		Warlock (std::string name, std::string title): _name(name), _title(title){
			std::cout << this->_name << ": This looks like another boring day." << std::endl;
		}
		~Warlock(){
			std::cout << this->_name << ": My job here is done!" << std::endl;
		}
		std::string const & getName() const{
			return (this->_name);
		}
		std::string const & getTitle() const{
			return (this->_title);
		}
		void setTitle(std::string const & title){
			this->_title = title;
		}
		void introduce() const{
			std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
		}
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string const & spellName);
		void launchSpell(std::string const & spellName, ATarget const & target);

	private:
		Warlock();
		Warlock(Warlock const & rhs);
		Warlock & operator=(Warlock const & rhs);

		std::string _name;
		std::string	_title;
//		std::map<std::string const, ASpell *> _spellList;
		SpellBook	_spellList;

};

#endif