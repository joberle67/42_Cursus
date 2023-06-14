#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
    public :
            Cat(void);
            Cat(const Cat &src);
            Cat &operator=(const Cat &src);
            ~Cat(void);
            Brain *getBrain() const;
            void makeSound(void) const;

    private :
        Brain *brain;
};

#endif