#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

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

	private:
		Warlock();
		Warlock(Warlock const & rhs);
		Warlock & operator=(Warlock const & rhs);

		std::string _name;
		std::string	_title;

};

#endif