#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
    public :
            Fixed(void);
            Fixed(int const &nb);
            Fixed(float const &nb);
            Fixed(Fixed const &tmp);
            
            Fixed &operator = (Fixed const &tmp);
            
            int getRawBits(void) const;
            void setRawBits(int const raw);

            float toFloat(void) const;
            int   toInt(void) const;
            
            ~Fixed(void);

    private :
    static const int byte;
                        int nb;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif