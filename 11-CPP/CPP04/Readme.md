# 42School : subtype polymorphism, abstract classes, interfaces in CPP04 project

## Purpose of the project
This is a light description of the project CPP04 ex03 called AMateria

Features of an interface :
  - An interface is a class in which all member functions are purely virtual.
  Thus, these functions must be overridden in derived classes.

  - Such a class cannot have any member variables.

To declare the class :
```C++
class IMateria
{
  public:
	  IMateria(void);
		IMateria(const IMateria &rhs);
		IMateria & operator=(const IMateria & rhs);
		virtual ~IMateria(void);

		IMateria(const std::string & type);
		const std::string & getType() const; //returns the materia type
		virtual IMateria *clone() const = 0; //clone an instance and create an instance of same type
		virtual void use(ICharacter & target) = 0; //display a message
}
```

