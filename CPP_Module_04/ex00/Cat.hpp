#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    public :
            Cat(void);
            Cat(const Cat &src);
            Cat &operator=(const Cat &src);
            ~Cat(void);
            void makeSound(void) const;

    private :
};

#endif