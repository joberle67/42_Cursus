#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public :
            Dog(void);
            Dog(const Dog &src);
            Dog &operator=(const Dog &src);
            virtual ~Dog(void);
            void makeSound(void) const;

    private :
};

#endif