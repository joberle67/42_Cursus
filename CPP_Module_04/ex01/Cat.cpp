#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
    this->~Cat();
    this->brain = new Brain(*src.getBrain());
    this->Animal::operator=(src);
    return (*this);
}

Cat::~Cat(void)
{
    delete this->brain;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}

void Cat::makeSound(void) const
{
    std::cout << "MIAAOUUU" << std::endl;
}