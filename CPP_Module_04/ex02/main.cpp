#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
{
		int i = 0;
		Animal *Animals[10];
		while ( i < 10)
		{
			if (i % 2 == 0)
				Animals[i] = new Dog();
			if (i % 2 == 1)
				Animals[i] = new Cat();
			i++;
		}
		std::cout << "DEEP COPY!!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		Dog copy(*(Dog *)Animals[4]);
		for (int i = 0; i < 100; ++i)
		{
			std::cout << copy.getBrain()->getIdea(i) << "    ";
			std::cout << ((Dog *)Animals[4])->getBrain()->getIdea(i) << std::endl;
		}
		std::cout << "-----------------------------"
				  << std::endl;
		for (int i = 0; i < 10; ++i)
			delete Animals[i];
	}
}
