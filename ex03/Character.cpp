#include "Character.hpp"

Character::Character() : name("Unamed")
{
	std::cout << "Character constructor default called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = 0;
	}
}

Character::Character(const std::string &name) : name(name)
{
	std::cout << "Character constructor by name called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = 0;
	}
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Character constructor copy called" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = 0;
	}
	copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		return;
	}
	if (!inventory[idx])
	{
		return;
	}
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		return;
	}
	if (!inventory[idx])
	{
		return;
	}
	inventory[idx]->use(target);
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory[i];
		inventory[i] = 0;
	}
}

void Character::copyInventory(const Character &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
	}
}
