#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
    public :
            WrongCat(void);
            WrongCat(const WrongCat &src);
            WrongCat &operator=(const WrongCat &src);
            ~WrongCat(void);
            void makeSound(void) const;
    private :

};

#endif