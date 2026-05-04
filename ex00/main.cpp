#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	Animal stackAnimal;
	Dog stackDog;
	Cat stackCat;
	Animal *pack[2];
	pack[0] = new Dog();
	pack[1] = new Cat();
	pack[0]->makeSound();
	pack[1]->makeSound();
	delete pack[0];
	delete pack[1];
	Dog dogCopy(stackDog);
	Cat catCopy(stackCat);
	(void)stackAnimal;
	(void)dogCopy;
	(void)catCopy;

	return 0;
}
