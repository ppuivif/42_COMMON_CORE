# 42School : subtype polymorphism, abstract classes, interfaces in CPP04 project

## Purpose of the project
This is a light description of the project CPP04 ex03 called AMateria

### Features of an abstract class :
  - A class is abstract when at least one member functions is purely virtual.</br>
  A purely virtual function can't be implemented and the class couln't be instancied.</br>
  It is declared as follow :
```C++
	virtual AMateria * clone() const = 0; //it is terminated with "= 0"
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Thus, these purely virtual functions must be overridden in derived (concrete) classes.
  - Such a class can have member variables.

To declare an abstract class, it could be named starting with the character 'A' :
```C++
class AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const & rhs);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria(void);

		virtual AMateria * clone() const = 0; //clone an instance and create an instance of same type
		virtual void use(ICharacter & target); //display a message

	protected:
		std::string _type;
};
```


### Features of an interface :
  - An interface is a class in which all member functions are purely virtual.
  Thus, these functions must be overridden in derived (concrete) classes.

  - Such a class cannot have any member variables.

To declare a class as an interface, it could be named starting with the character 'I' :
```C++
class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {}

		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(std::string const & type) = 0;
};
```

To understand the subject :<br>
A materia could be compared to a container in which we would have a special power (throw a fireball, throw an ice ball, cure, ...).<br>
Now imagine a belt on which we could hang up a single or several materia (containing a special power or not).<br>
We could take an available materia (leaving on the floor) and equip it on the belt.<br>
If there are 4 locations on the belt, we could equip it with 4 materia maximum.<br>
If there are only one available location, only one materia could be taken and equiped.<br>
If there is any available location left, a materia should be unequiped to equip a new one.<br>

