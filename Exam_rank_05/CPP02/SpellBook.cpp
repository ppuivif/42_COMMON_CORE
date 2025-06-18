#include "SpellBook.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

SpellBook::~SpellBook(){
	for (std::map<std::string const, ASpell *>::iterator it = this->_spellList.begin(); it != this->_spellList.end(); it++)
		delete it->second;
	this->_spellList.clear();
}

void SpellBook::learnSpell(ASpell * spell){
	if (spell){
		std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spell->getName());
		if (it == this->_spellList.end()){
			ASpell *clone = spell->clone();
			this->_spellList.insert(std::pair<std::string const, ASpell *>(spell->getName(), clone));
		}
	}
}

void SpellBook::forgetSpell(std::string const & spellName){
	std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spellName);
	if (it != this->_spellList.end()){
		delete it->second;
		this->_spellList.erase(it);
	}
}

ASpell * SpellBook::createSpell(std::string const & spellName){
	std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spellName);
	if (it != this->_spellList.end()){
		ASpell *clone = it->second->clone();
		return (clone);
	}
	return (NULL);
}