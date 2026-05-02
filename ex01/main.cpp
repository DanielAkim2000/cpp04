#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	const int count = 6;
	Animal *animals[count];

	for (int idx = 0; idx < count; ++idx)
	{
		if (idx < count / 2)
		{
			animals[idx] = new Dog();
			static_cast<Dog *>(animals[idx])->setIdea(0, "Chase the ball");
		}
		else
		{
			animals[idx] = new Cat();
			static_cast<Cat *>(animals[idx])->setIdea(0, "Find a warm spot");
		}
	}

	Dog originalDog;
	originalDog.setIdea(0, "Guard the house");
	Dog copyDog(originalDog);
	originalDog.setIdea(0, "Nap time");

	std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied dog idea: " << copyDog.getIdea(0) << std::endl;

	Cat originalCat;
	originalCat.setIdea(1, "Climb the shelf");
	Cat assignedCat;
	assignedCat = originalCat;
	originalCat.setIdea(1, "Ignore humans");

	std::cout << "Original cat idea: " << originalCat.getIdea(1) << std::endl;
	std::cout << "Assigned cat idea: " << assignedCat.getIdea(1) << std::endl;

	for (int idx = 0; idx < count; ++idx)
	{
		delete animals[idx];
	}

	return 0;
}
