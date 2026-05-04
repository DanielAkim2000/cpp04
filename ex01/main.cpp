#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	const int count = 4;
	Animal *animals[count];

	for (int idx = 0; idx < count; ++idx)
	{
		if (idx < count / 2)
		{
			animals[idx] = new Dog();
		}
		else
		{
			animals[idx] = new Cat();
		}
	}

	for (int idx = 0; idx < count; ++idx)
	{
		delete animals[idx];
	}

	Dog basicDog;
	basicDog.setIdea(0, "Guard the house");
	Dog copyDog(basicDog);
	basicDog.setIdea(0, "Nap time");
	std::cout << "Dog ideas: " << basicDog.getIdea(0) << " / " << copyDog.getIdea(0) << std::endl;

	Cat basicCat;
	basicCat.setIdea(0, "Find a warm spot");
	Cat copyCat(basicCat);
	basicCat.setIdea(0, "Ignore humans");
	std::cout << "Cat ideas: " << basicCat.getIdea(0) << " / " << copyCat.getIdea(0) << std::endl;

	return 0;
}
