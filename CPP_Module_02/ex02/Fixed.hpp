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
            bool   operator>(Fixed tmp) const;
            bool   operator<(Fixed tmp) const;
            bool   operator>=(Fixed tmp) const;
            bool   operator<=(Fixed tmp) const;
            bool   operator==(Fixed tmp) const;
            bool   operator!=(Fixed tmp) const;

            float operator+(Fixed tmp) const;
            float operator-(Fixed tmp) const;
            float operator*(Fixed tmp) const;
            float operator/(Fixed tmp) const;

            Fixed operator++();
            Fixed operator--();
            Fixed operator++(int);
            Fixed operator--(int);
            
            int getRawBits(void) const;
            void setRawBits(int const raw);

            float toFloat(void) const;
            int   toInt(void) const;

            static Fixed &min(Fixed &nb1, Fixed &nb2);
            static const Fixed &min(Fixed const &nb1, Fixed const &nb2);
            static Fixed &max(Fixed &nb1, Fixed &nb2);
            static const Fixed &max(Fixed const &nb1, Fixed const &nb2);
            
            ~Fixed(void);

    private :
    static const int byte;
                        int nb;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif