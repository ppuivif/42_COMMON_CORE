#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook{

	public:
		SpellBook(){}
		~SpellBook();
		
		void learnSpell(ASpell * spell);
		void forgetSpell(std::string const & spellName);
		ASpell * createSpell(std::string const & spellName);

	private:
		SpellBook(SpellBook const & rhs);
		SpellBook & operator=(SpellBook const & rhs);

		std::map<std::string const, ASpell *> _spellList;


};

#endif