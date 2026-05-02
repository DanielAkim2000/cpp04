#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		slots[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		slots[i] = 0;
	}
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete slots[i];
			slots[i] = 0;
			if (other.slots[i])
			{
				slots[i] = other.slots[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		delete slots[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!slots[i])
		{
			slots[i] = m->clone();
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (slots[i] && slots[i]->getType() == type)
		{
			return slots[i]->clone();
		}
	}
	return 0;
}
