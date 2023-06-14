#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal
{
    public :
            WrongAnimal(void);
            WrongAnimal(const WrongAnimal &src);
            WrongAnimal &operator=(const WrongAnimal &src);
            virtual ~WrongAnimal(void);
            virtual void makeSound(void) const;
            std::string getType(void) const;
    protected :
            std::string type;

};

#endif