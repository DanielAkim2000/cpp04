#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static void subjectScenario()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *learned = new Ice();
	src->learnMateria(learned);
	delete learned;
	learned = new Cure();
	src->learnMateria(learned);
	delete learned;

	ICharacter *me = new Character("me");
	AMateria *tmp = 0;
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
}

static void inventoryLimits()
{
	Character hero("hero");
	hero.equip(new Ice());
	hero.equip(new Cure());
	hero.equip(new Ice());
	hero.equip(new Cure());
	AMateria *extra = new Ice();
	hero.equip(extra);
	delete extra;

	Character target("target");
	for (int i = 0; i < 4; ++i)
	{
		hero.use(i, target);
	}
	hero.use(4, target);
}

static void deepCopyChecks()
{
	Character a("alpha");
	AMateria *dropped = new Ice();
	a.equip(dropped);
	a.equip(new Cure());

	Character b(a);
	a.unequip(0);
	delete dropped;

	Character c("charlie");
	c = a;

	Character target("dummy");
	b.use(0, target);
	b.use(1, target);
	c.use(0, target);
}

static void unknownMateria()
{
	MateriaSource src;
	AMateria *m = src.createMateria("fire");
	if (m)
	{
		delete m;
	}
}

int main()
{
	subjectScenario();
	inventoryLimits();
	deepCopyChecks();
	unknownMateria();
	return 0;
}
