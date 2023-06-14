#include "Animal.hpp"

Animal::Animal(void)
{
    std :: cout << "Animal default constructor called" << std::endl;
    this->type = "";
}

Animal::Animal(std::string type)
{
    std::cout << "Animal assignement constructor called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &tmp)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = tmp;
}

Animal &Animal::operator=(const Animal &tmp)
{
    std::cout << "Animal copy operator called" << std::endl;
    this->type = tmp.type;
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << "this is a sound of a animal" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

Animal::~Animal(void)
{
    std::cout << "Animal " << this->type 
        << " say goodbye" << std::endl;
}