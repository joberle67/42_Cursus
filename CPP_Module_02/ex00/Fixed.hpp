#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public :
            Fixed(void);
            Fixed(Fixed const &cp);
            void operator = (Fixed const &cp);
            int getRawBits(void) const;
            void setRawBits(int const raw);
            ~Fixed(void);

    private :
                int nb;
                static const int fixe = 8;
};

#endif