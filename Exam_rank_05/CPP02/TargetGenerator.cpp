#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::~TargetGenerator(){
	for (std::map<std::string const, ATarget *>::iterator it = this->_targetList.begin(); it != this->_targetList.end(); it++)
		delete it->second;
	this->_targetList.clear();
}

void TargetGenerator::learnTargetType(ATarget * target){
	if (target){
		std::map<std::string const, ATarget *>::iterator it = this->_targetList.find(target->getType());
		if (it == this->_targetList.end()){
			ATarget *clone = target->clone();
			this->_targetList.insert(std::pair<std::string const, ATarget *>(target->getType(), clone));
		}
	}
}

void TargetGenerator::forgetTargetType(std::string const & targetName){
	std::map<std::string const, ATarget *>::iterator it = this->_targetList.find(targetName);
	if (it != this->_targetList.end()){
		delete it->second;
		this->_targetList.erase(it);
	}
}

ATarget * TargetGenerator::createTarget(std::string const & targetName){
	std::map<std::string const, ATarget *>::iterator it = this->_targetList.find(targetName);
	if (it != this->_targetList.end()){
		ATarget *clone = it->second->clone();
		return (clone);
	}
	return (NULL);
}