#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public :
            virtual ~Animal();

            std::string getType(void) const;
			virtual void makeSound(void) const = 0;
    protected :
            std::string type;
};

#endif
