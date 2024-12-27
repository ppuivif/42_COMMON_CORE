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

To understand the subject :<br>
A materia could be compared to a container in which we would have a special power (throw a fireball, throw an ice ball, cure, ...).<br>
Now imagine a belt on which we could hang up a single or several materia (containing a special power or not).<br>
We could take an available materia (leaving on the floor) and equip it on the belt.<br>
If there are 4 locations on the belt, we could equip it with 4 materia maximum.<br>
If there are only one available location, only one materia could be taken and equiped.<br>
If there is any available location left, a materia should be unequiped to equip a new one.<br>

