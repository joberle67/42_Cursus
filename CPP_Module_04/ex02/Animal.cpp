#include "Animal.hpp"

std::string Animal::getType(void) const
{
    return (this->type);
}

Animal::~Animal(void)
{
    std::cout << "Animal " << this->type 
        << " say goodbye" << std::endl;
}