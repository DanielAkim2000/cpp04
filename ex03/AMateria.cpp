#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "AMeteria constructor by type" << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType(void) const
{
	return (type);
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// null
	}
	return (*this);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
