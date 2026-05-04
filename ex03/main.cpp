#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	MateriaSource extraSrc;
	extraSrc.learnMateria(new Ice());
	extraSrc.learnMateria(new Cure());
	AMateria *unknown = extraSrc.createMateria("fire");
	if (unknown)
	{
		delete unknown;
	}

	Character hero("hero");
	AMateria *toDrop = extraSrc.createMateria("cure");
	hero.equip(toDrop);
	hero.equip(extraSrc.createMateria("ice"));
	hero.equip(extraSrc.createMateria("cure"));
	hero.equip(extraSrc.createMateria("ice"));
	AMateria *extra = extraSrc.createMateria("cure");
	hero.equip(extra);
	delete extra;

	Character target("target");
	hero.use(0, target);
	hero.use(1, target);
	hero.unequip(0);
	delete toDrop;
	hero.use(0, target);

	return 0;
}
