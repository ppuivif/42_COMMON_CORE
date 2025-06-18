#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{

	public:
		TargetGenerator(){}
		~TargetGenerator();
		TargetGenerator & operator=(TargetGenerator const & rhs);
		
		void learnTargetType(ATarget * target);
		void forgetTargetType(std::string const & targetName);
		ATarget * createTarget(std::string const & targetName);

	private:
		TargetGenerator(TargetGenerator const & rhs);
		std::map<std::string const, ATarget *> _targetList;


};

#endif