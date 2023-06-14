#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    public :
            Animal(void);
            Animal(std::string type);
            Animal(const Animal &tmp);
            Animal &operator=(const Animal &tmp);
            virtual ~Animal();

            std::string getType(void) const;
            virtual void makeSound(void) const;


    protected :
            std::string type;
};

#endif