#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

/*void Warlock::learnSpell(ASpell * spell){
	if (spell){
		std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spell->getName());
		if (it == this->_spellList.end()){
			ASpell *clone = spell->clone();
			this->_spellList.insert(std::pair<std::string const, ASpell *>(spell->getName(), clone));
		}
	}
}

void Warlock::forgetSpell(std::string const & spellName){
	std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spellName);
	if (it != this->_spellList.end()){
		delete it->second;
		this->_spellList.erase(it);
	}
}

void Warlock::launchSpell(std::string const & spellName, ATarget const & target){
	std::map<std::string const, ASpell *>::iterator it = this->_spellList.find(spellName);
	if (it != this->_spellList.end())
		it->second->launch(target);
}*/

void Warlock::learnSpell(ASpell * spell){
	if (spell)
		this->_spellList.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const & spellName){
	this->_spellList.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string const & spellName, ATarget const & target){
	ASpell * spell = this->_spellList.createSpell(spellName);
	if (spell){
		spell->launch(target);
		delete spell;
	}
}
